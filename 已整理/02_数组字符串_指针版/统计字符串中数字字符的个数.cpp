#define  _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
/*题目 2：统计字符串中数字字符的个数
size_t count_digits(const char* str);
- 统计 str 中 '0'~`'9'` 的个数并返回
- 测试："a1b2c345" → 5；"hello" → 0；"" → 0
- 涉及知识点：my_strlen 的遍历模式（while (*p)）、字符范围判断、size_t 返回、%zu 打印、const char* 形参
*/
size_t my_streln(const char* p)
{
	size_t count = 0;
	while (*p >='0'&&*p<='9')//数字字符需要使用’’
	{
		count++;
		p++;
	}
	return count;
}
int main()
{
	//需要有一个数组来提供真实的内存，存储空间
	char arr[100];
	printf("请输入\n");
	scanf("%s", arr);
	
	size_t my_streln(const char* p);
	printf("%zu ", my_streln(arr));
}