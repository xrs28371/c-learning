#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stddef.h>

/*
日期：2026-10-17
建议用时：60–90 分钟。先独立完成，今天学完文件操作后再做第 3 题。

第 1 题：返回最大元素的地址
实现 find_max：返回数组中最大元素的指针，不要修改数组里的值。
如果 arr 是 NULL 或 len <= 0，返回 NULL。
测试：{3, 1, 9, 2}、{9, 1, 2}、{1, 2, 9}、{7}、长度为 0。

第 2 题：统计整个字符串里的数字字符
实现 count_digits：统计字符串中 '0' 到 '9' 的总个数。
str 是 NULL 时返回 0。建议用 const char* 遍历，不要修改字符串。
测试："a1b2c345" 得到 5；"hello" 得到 0；"" 得到 0；"123" 得到 3。

第 3 题：文件读写（学完 fopen / fputs 或 fprintf / fgets / fclose 后做）
在 main 中完成：
1. 用 "w" 模式打开 practice_output.txt，写入三行文字。
2. 检查打开、写入和关闭是否成功。
3. 再用 "r" 模式打开该文件，用 fgets 逐行读出并打印。
4. 检查打开和关闭是否成功。

提示：文件操作要检查 fopen 的返回值；成功打开的文件最终要 fclose。
Visual Studio：可通过“源文件 -> 添加 -> 现有项”添加本 .c 文件。
*/

int* find_max(int* arr, int len);
size_t count_digits(const char* str);

int main(void)
{
    /* 在这里逐题完成并测试。 */
    return 0;
}
