#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include<ctype.h>
int main1()
{
	int a[] = { 1, 2, 3, 4 };
	printf("%zu\n", sizeof(a));//16  数组的字节大小
	printf("%zu\n", sizeof(a + 1));//4   &a[1]
	printf("%zu\n", sizeof(a[1]));//4     a[1]当中的数组字节大小
	printf("%zu\n", sizeof(&a));// 4     整个数组的地址
	printf("%zu\n", sizeof(&a + 1));// 4     数组后一位的地址
	printf("%zu\n", sizeof(&a[0]));// 4   数组首元素的地址
	printf("%zu\n", sizeof(&a[0] + 1));//4   数组第二位元素的地址
	return 0;
}
int main2()
{
	// 指针+1加几个字节   去掉*求sizeof   不管几级指针都是去一个*
	char* a[] = { "work","at","alibaba" };//sizeof(char*)是四个字节
	char** pa = a;
	pa++;
	printf("%s\n", *pa);
	return 0;
}
//字符函数 字符串函数
int main()
{
	char ch = 'a';
	if (isdigit(ch))
	{
		printf("是数字字符\n");
	}
	else
	{
		printf("是数字字符\n");
	}
	return 0；
}
