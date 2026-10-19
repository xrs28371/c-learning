#define  _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
int main()
//for(表达式1，表达式2.表达式3）
//表达式1 用于初始化
//表达式2 用于循环结束条件的判断
//表达式3 用于循环变量的调整
{
	
	
	for (int i = 1;i <= 10;i++)
	{
		printf("%d\n", i);
	}
	int sum = 0;
	
	
	
	for (int a = 1; a <= 100;a++)
	{
		if (a % 2 == 0)
		{
			sum += a;
		}
	}
	printf("%d", sum);
	
	
	
	return 0;
}