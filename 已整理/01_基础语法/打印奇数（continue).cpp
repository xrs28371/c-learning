#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main()
{
	int a = 0;
	int b;
	scanf("%d",&a);
	for (b = 1; b<=a; b++)
	{
		if (b % 2 == 0)
		{
			continue;
		}
		printf("%2d", b);
	}
	return 0;
}