#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main()
{
	int i = 0;
	int n=0;
	int sum = 0;

	scanf("%d", &n);
	while (i <= n)
	{
		i++;
		if (i == 5)
		{
			break;
		}
		sum += i;
	}
	printf("%d", sum);
	return 0;
}