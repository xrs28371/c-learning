#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
int main()
{
	int a = 0;
	int b = 0;
	while (scanf("%d%d", &a, &b) != EOF)
	{
		printf("除法结果为%d\n", a / b);
		printf("小数除法结果为%.3f\n", (double)a / b);

	}
	return 0;
}