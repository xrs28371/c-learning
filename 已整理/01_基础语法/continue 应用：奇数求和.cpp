#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main()
{
	int n;
	int i = 1;
	int sum=0;
	scanf("%d", &n);
	while (i <= n)
	{
		if (i % 2 == 0)
		{
			i++;
			continue;
		}
		sum += i;
		i++;
	}
	printf("%d", sum);
	return 0;
}
	