#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
int main()
{
	int i = 1;
	while(i<=10)
	{
		if (i == 5)
		{
			break;//结束循环,一般只在循环和switch里面使用
		}
		printf("%d\n", i);
		i++;
		
	}
	
	int a = 1;
	while (a <= 100)
	{
		if (a % 3 == 0)
		{
			printf("第一个被三整除的数字为%d\n", a);
			break;
		}
		a++;
	}
	
	int b = 0;
	for (b = 1;b <= 10;b++)
	{
		if (b == 5)
		{
			continue;
		}
		printf("%d\n", b);
	}

	int x=0;
	while (x <= 10)
	{
		if (x == 5)
		{
			x++;
			continue;
		}
		
		printf("%d\n", x);
		x++;
	}
	
	int y = 0;
	for (y = 1;y <= 100;y++)
	{
		if (y % 3 != 0)
		{
			continue;
		}
		printf("%d\n", y);

	}

	
	
	
	return 0;
}
