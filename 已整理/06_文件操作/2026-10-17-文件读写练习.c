#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

/*
日期：2026-10-17
主题：fopen、fputc、fgetc、fclose、EOF

第 1 题：写入字母
实现 write_letters：用 "w" 模式打开 letters.txt，依次写入 a 到 z。
检查文件是否打开成功；检查写入和 fclose 是否成功；成功返回 0，失败返回 1。
注意："w" 会清空同名旧文件。

第 2 题：逐字符读取并计数
实现 read_and_count：用 "r" 模式打开 letters.txt，逐字符读取并显示到屏幕，
读到 EOF 时停止，统计字符数量并打印。检查打开和关闭是否成功。
测试：先运行第 1 题，数量应为 26；再把 letters.txt 清空，数量应为 0。
挑战：在文件里放入多行文字，观察换行也会作为字符被计数。

提示：fgetc 的返回类型用 int 保存，这样才能和 EOF 比较。
相对路径 letters.txt 位于程序的当前工作目录；两题使用同一个路径。
*/

int write_letters(void)
{
    /* 在这里完成第 1 题。 */
    return 0;
}

int read_and_count(void)
{
    /* 在这里完成第 2 题。 */
    return 0;
}

int main(void)
{
    if (write_letters() != 0)
    {
        return 1;
    }

    if (read_and_count() != 0)
    {
        return 1;
    }

    return 0;
}
