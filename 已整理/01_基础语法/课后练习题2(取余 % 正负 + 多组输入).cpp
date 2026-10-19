#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
int main()
{
	int n = 0;
	while (scanf("%d", &n) != EOF)
		printf("计算结果为%d\n", n % 5);
	return 0;
}