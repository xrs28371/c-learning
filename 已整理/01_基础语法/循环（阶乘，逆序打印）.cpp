#define  _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
int main()//while的作用在条件为真时重复执行代码，适合循环未知的场景
{
	int i = 1;
	while (i<=10)
	{
		printf("%d\n", i);
		i++;
	}

	//练习：输入一个正整数，逆序打印每一位
	//123%10=3
	//12%10=3
	//1%10=1
	int a = 0;
	scanf("%d", &a);
	while (a != 0)
	{
		printf("%d", a % 10);
		a = a / 10;

	}
	
	//求5的阶乘

	int b = 0;
	scanf("%d", &b);
	int x = 1;
	int ret = 1;
	while (x <= b)
	{
		//这里是在求阶乘
		ret = ret * x;
		//循环条件发生变化，此时++操作
		x++;
	}
	printf("%d\n", ret);
	
	
	return 0;
}