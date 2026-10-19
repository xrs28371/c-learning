#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
int main()
{
	int n = 0;
	while(scanf("%d", &n)!=EOF)
	if (n >= 10)
	{
		printf("n>=10\n");
	}
	else if (n >= 5 && n < 10)
	{
		printf(" n>= 5 && n < 10");
	}
	else
	{
		printf("n<5");
	}
}