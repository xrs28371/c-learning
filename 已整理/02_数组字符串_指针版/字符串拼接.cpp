#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
/*- 把 src 这个字符串拼接到 dest 的末尾（覆盖掉 dest 原来的结尾 '\0'，然后在新末尾补上 '\0'）
- 直接修改 dest，函数没有返回值（void）
- 禁止使用库函数 strcat
- const char* src 表示 src 只读，你只能读它、不能改它
测
*/
void my_strcat(char* dest, const char* src)
{
	char* p = dest;
	while (*p != '\0')
	{
		p++;
	}
	while (*src != '\0')
	{
		*p = *src;
		p++;
		src++;
	}
	*p = '\0';


}

int main()
{
	char dest[20] = "Hello";
	char src[] = "World!";
	my_strcat(dest, src);
	//void没有返回值不能直接打印 需要先调用然后再打印你需要的数据

	printf("%s ", dest);
	return 0;


}