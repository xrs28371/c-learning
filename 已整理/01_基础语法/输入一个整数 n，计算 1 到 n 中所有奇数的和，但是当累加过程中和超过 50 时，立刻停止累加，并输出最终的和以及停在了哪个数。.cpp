#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main()
{
	int n = 0;
	scanf("%d", &n);
	int sum = 0;
	int i = 0;
	while (i<n)
	{
		i++;
		if (i % 2 == 0)
		{
			continue;
		}
		sum += i;
		if (sum > 50)
			break;
	}
	printf("最终的和%d\n", sum);
	printf("停在的值%d\n", i);
    return 0;
}
