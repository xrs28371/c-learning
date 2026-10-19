#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
int main()
{
	double a = 0;
	double b = 0;
	while (scanf("%lf%lf", &a, &b) != EOF)
	{
		printf("两者的平均值为%.2f\n", (a + b) / 2);
	}
	return 0;
}