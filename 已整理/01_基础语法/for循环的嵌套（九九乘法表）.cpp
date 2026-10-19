#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
int main()
{
	for (int i = 1;i <= 9;i++)//外层控制行数
	{
		for (int j = 1;j <= i;j++)//内层，控制每行的算式个数
		{
			printf("%d*%d=%2d ", j, i, j * i);
		}
		printf("\n");
		
	}
	return 0;
}