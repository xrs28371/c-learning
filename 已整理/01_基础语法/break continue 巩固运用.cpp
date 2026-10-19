#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main()
{
	int n = 0;
	scanf("%d", &n);
	int i = 0;
	int sum = 0;
	while (i <= n)
	{
		i++;
		if (i % 3 == 0)
		{
			continue;
		}
		sum += i;
		if (sum > 100)
			break;
     }
	printf("最终的累加和%d \n", sum);
	printf("停止时停止在哪一个数字%d", i);
	return 0;
}
