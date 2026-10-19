#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
int main()
{
	int i = 1;
	int sum = 0;
	while (1)
	{
		sum += i;
		if (sum >= 100)
		{
			break;
		}
		i++;
	}
	printf("%d", sum);
	return 0;
}