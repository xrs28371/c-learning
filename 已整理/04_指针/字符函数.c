#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include<ctype.h>
#include<string.h>
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
int main3()
{
	char ch = 'a';
	if (isdigit(ch))
	{
		printf("是数字字符\n");
	}
	else
	{
		printf("不是数字字符\n");
	}
	return 0;
}
int main4()
{
	char ch = 'a';
	if (islower(ch))
	{
		printf("是大写字符\n");
	}
	else
	{
		printf("不是大写字符\n");
	}
	return 0;
}
int main5()
{
	char arr[] = "abcdefg";//本身是数组 那字符值赋值在里面
	int i = 0;
	while (arr[i] != '\0')
	{
		if (islower(arr[i]))
		{
			//转大写
			arr[i] = arr[i] - 32;
		}
		i++;
	}
	
	printf("%s", arr);
	return 0;
}

//字符转换函数
//tolower   大写转小写
//toupper  小写转大写
int main5()
{
	char arr[] = "abcdefg";//本身是数组 那字符值赋值在里面
	int i = 0;
	while (arr[i] != '\0')
	{
		if (islower(arr[i]))
		{
			//转大写
			//arr[i] = arr[i] - 32;
			arr[i] = toupper(arr[i]);
		}
		i++;
	}

	printf("%s", arr);
	return 0;
}
//如果传入的没有对应大小写   就不会转化