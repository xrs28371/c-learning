#include <ctype.h>
#include <errno.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "library.h"

/* 返回 1 表示成功，0 表示输入无效，-1 表示输入结束或读取失败。
 * 每次提示输入一项，整行读取完再检查，避免剩余字符串到下一项。 */
static int ReadLine(const char* prompt, char* text, size_t capacity)
{
    assert(prompt);
    assert(text);
    assert(capacity > 0);
    fputs(prompt, stdout);
    fflush(stdout);

    size_t length = 0;
    int invalid = 0;
    int ch;
    while ((ch = getchar()) != '\n' && ch != EOF)
    {
        if (ch == '\0')
            invalid = 1;
        if (length < capacity - 1)
            text[length++] = (char)ch;
        else
            invalid = 1;
    }
    text[length] = '\0';
    if (ferror(stdin))
    {
        perror("读取输入失败");
        return -1;
    }
    if (ch == EOF && length == 0 && !invalid)
        return -1;
    if (invalid)
    {
        puts("输入过长或包含无效字符，本次操作取消。");
        return 0;
    }
    return 1;
}

int EquipmentReadInt(const char* prompt, int* value)
{
    assert(value);
    char line[256];
    int result = ReadLine(prompt, line, sizeof line);
    if (result != 1)
        return result;

    char* end;
    errno = 0;
    long number = strtol(line, &end, 10);
    if (end == line || errno == ERANGE || number < INT_MIN || number > INT_MAX)
    {
        puts("请输入 int 范围内的整数，本次操作取消。");
        return 0;
    }
    while (isspace((unsigned char)*end))
        end++;
    if (*end != '\0')
    {
        puts("整数后不能夹带其他内容，本次操作取消。");
        return 0;
    }
    /* 检查通过后才修改调用者的变量。 */
    *value = (int)number;
    return 1;
}

static int ReadWord(const char* prompt, char* value, size_t capacity)
{
    assert(value);
    assert(capacity > 0);
    char line[256];
    int result = ReadLine(prompt, line, sizeof line);
    if (result != 1)
        return result;

    char* start = line;
    while (isspace((unsigned char)*start))
        start++;
    char* end = start;
    while (*end != '\0' && !isspace((unsigned char)*end))
        end++;
    size_t length = (size_t)(end - start);
    while (isspace((unsigned char)*end))
        end++;
    if (length == 0 || length >= capacity || *end != '\0')
    {
        printf("请输入不含空格的名称或分类，最多 %zu 字节，本次操作取消。\n", capacity - 1);
        return 0;
    }
    memcpy(value, start, length);
    value[length] = '\0';
    return 1;
}

/* record 指向一条器材记录，展示和按编号查找共用这个打印函数。 */
static void PrintEquipment(const Equipment* record)
{
    assert(record);
    printf("编号：%d 名称：%s 分类：%s 总数量：%d 已借出：%d 可借：%d\n",
        record->id, record->name, record->category, record->total,
        record->borrowed, record->total - record->borrowed);
}

/* 新增：所有检查通过后，才调用底层插入函数。 */
void EquipmentAdd(B* ps)
{
    assert(ps);
    Equipment tmp = { 0 };
    if (EquipmentReadInt("请输入编号：", &tmp.id) != 1)
        return;
    if (tmp.id <= 0)
    {
        puts("编号必须是正整数。");
        return;
    }
    if (EquipmentFind(ps, tmp.id) != -1)
    {
        puts("编号已经存在，新增失败。");
        return;
    }
    if (ReadWord("请输入名称（最多39字节）：", tmp.name, sizeof tmp.name) != 1)
        return;
    if (ReadWord("请输入分类（最多19字节）：", tmp.category, sizeof tmp.category) != 1)
        return;
    if (EquipmentReadInt("请输入总数量：", &tmp.total) != 1)
        return;
    if (tmp.total < 0)
    {
        puts("总数量不能为负数。");
        return;
    }
    /* 新增记录没有发生借出，直接设为零。 */
    tmp.borrowed = 0;
    int pos;
    printf("插入位置范围为 0 到 %d（含两端）。\n", ps->size);
    if (EquipmentReadInt("请输入插入位置：", &pos) != 1)
        return;
    if (pos < 0 || pos > ps->size)
    {
        puts("插入位置无效。");
        return;
    }
    BInsert(ps, pos, tmp);
    puts("新增成功。");
}

//删除：按编号删除。不存在时提示；仍有器材借出时拒绝删除。
void EquipmentDelete(B* ps, int x)
{
    assert(ps);
    if (EquipmentReadInt("请输入删除的编号：", &x) != 1)
        return;
    if (x <= 0)
    {
        puts("编号必须是正整数。");
        return;
    }
    /* x 是编号，pos 才是这个编号所在的数组下标。 */
    int pos = EquipmentFind(ps, x);
    if (pos == -1)
    {
        puts("没有找到该器材，无法删除。");
        return;
    }
    if (ps->arr[pos].borrowed != 0)
    {
        puts("仍有器材借出，无法删除。");
        return;
    }
    BErase(ps, pos);
    puts("删除成功。");
}

//修改：按编号修改名称、分类和总数量。编号保持不变。
//新总数量不能小于当前已借出数量；失败不能破坏原记录。
void EqiupmentRevise(B* ps, int x)
{
    assert(ps);
    if (EquipmentReadInt("请输入要修改的器材编号：", &x) != 1)
        return;
    if (x <= 0)
    {
        puts("编号必须是正整数。");
        return;
    }
    int pos = EquipmentFind(ps, x);
    if (pos == -1)
    {
        puts("没有找到该器材。");
        return;
    }
    // 复制原记录，保留编号和已借出数量
    Equipment temp = ps->arr[pos];
    if (ReadWord("请输入新名称（最多39字节）：", temp.name, sizeof temp.name) != 1)
        return;
    if (ReadWord("请输入新分类（最多19字节）：", temp.category, sizeof temp.category) != 1)
        return;
    if (EquipmentReadInt("请输入新总数量：", &temp.total) != 1)
        return;
    if (temp.total < temp.borrowed)
    {
        puts("总数量不能小于已借出数量，也不能为负数。");
        return;
    }
    // 全部检查通过，再修改顺序表中的记录
    ps->arr[pos] = temp;
    puts("修改成功。");
}

//业务函数共用的查找接口：返回匹配下标，不存在返回 -1。
int EquipmentFind(B* ps, int id)
{
    assert(ps);
    for (int i = 0; i < ps->size; i++)
    {
        if (ps->arr[i].id == id)
            return i;
    }
    return -1;
}

/* 菜单中的查找操作：只显示找到的那一条。 */
void EquipmentSearch(B* ps)
{
    assert(ps);
    int id;
    if (EquipmentReadInt("请输入要查找的编号：", &id) != 1)
        return;
    if (id <= 0)
    {
        puts("编号必须是正整数。");
        return;
    }
    int pos = EquipmentFind(ps, id);
    if (pos == -1)
    {
        puts("没有找到该器材。");
        return;
    }
    PrintEquipment(&ps->arr[pos]);
}

//展示：按当前顺序显示全部器材，包含可借数量；空表要有提示。
void EqiupmentShow(B* ps)
{
    assert(ps);
    if (ps->size == 0)
    {
        puts("当前顺序表为空。");
        return;
    }
    for (int i = 0; i < ps->size; i++)
        PrintEquipment(&ps->arr[i]);
}

//借出：数量必须是正整数且不能超过可借数量。
void EqiupmentBorrowed(B* ps, int id, int x)
{
    assert(ps);
    if (EquipmentReadInt("请输入编号：", &id) != 1)
        return;
    if (id <= 0)
    {
        puts("编号必须是正整数。");
        return;
    }
    int pos = EquipmentFind(ps, id);
    if (pos == -1)
    {
        puts("输入的编号不存在。");
        return;
    }
    if (EquipmentReadInt("请输入借出的数量：", &x) != 1)
        return;
    int available = ps->arr[pos].total - ps->arr[pos].borrowed;
    if (x <= 0 || x > available)
    {
        puts("借出数量必须大于零，并且不能超过可借数量。");
        return;
    }
    ps->arr[pos].borrowed += x;
    printf("借出成功，当前已借出 %d 件。\n", ps->arr[pos].borrowed);
}

//归还：数量必须是正整数且不能超过已借出数量。
void EquipmentReturn(B* ps, int id, int x)
{
    assert(ps);
    if (EquipmentReadInt("请输入编号：", &id) != 1)
        return;
    if (id <= 0)
    {
        puts("编号必须是正整数。");
        return;
    }
    int pos = EquipmentFind(ps, id);
    if (pos == -1)
    {
        puts("输入的编号不存在。");
        return;
    }
    if (EquipmentReadInt("请输入归还的数量：", &x) != 1)
        return;
    if (x <= 0 || x > ps->arr[pos].borrowed)
    {
        puts("归还数量必须大于零，并且不能超过已借出数量。");
        return;
    }
    ps->arr[pos].borrowed -= x;
    printf("已归还 %d 件，当前已借出 %d 件。\n", x, ps->arr[pos].borrowed);
}

//统计：种类数、总件数、已借出总件数、可借总件数。
void EquipmentStatistics(B* ps)
{
    assert(ps);
    long long totalCount = 0;
    long long borrowedCount = 0;
    for (int i = 0; i < ps->size; i++)
    {
        totalCount += ps->arr[i].total;
        borrowedCount += ps->arr[i].borrowed;
    }
    printf("器材种类数：%d\n", ps->size);
    printf("器材总件数：%lld\n", totalCount);
    printf("已借出总件数：%lld\n", borrowedCount);
    printf("可借总件数：%lld\n", totalCount - borrowedCount);
}

//菜单已经读取了退出选项，这里只检查选项并释放资源。
void EquipmentExit(B* ps, int x)
{
    assert(ps);
    if (x != 0)
    {
        puts("退出选项必须为0。");
        return;
    }
    Bdestory(ps);
    puts("顺序表内存已释放，程序结束。");
}
