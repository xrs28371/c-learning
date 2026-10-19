#define  _CRT_SECURE_NO_WARNINGS
#include<stdio.h>//计算正整数转化为二进制有几个1
int main()
{
	int count = 0;
	int num = 0;
	while (scanf("%d", &num) != EOF)
	{
		while (num != 0)
		{
			if ((num & 1) == 1&& num<=31)
			{
				count++;
			}
			num >>= 1;
		}
		printf("%d\n", count);
	}
	return 0;
}