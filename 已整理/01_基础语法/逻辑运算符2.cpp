#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
int main()
{
	int year = 0;
	while(scanf("%d", &year)!=EOF)
	if ((year % 4 == 0) && (year % 100 != 0)|| (year % 400 ==0))
	{
		printf("是闰年\n",year);
	}
	else
	{
		printf("不是闰年\n", year);
	}
	return 0;
}