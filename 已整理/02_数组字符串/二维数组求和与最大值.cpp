#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
int main()
{
	int i = 0;
	int j = 0;
	int arr[3][3];
	printf("请输入整数\n");
	for (int i = 0;i < 3;i++)
	{
		for (int j = 0;j < 3;j++)
		{
			scanf("%d", &arr[i][j]);
		}
	}
	printf("输出数组\n");
	for (int i = 0;i < 3;i++)
	{
		printf("\n");
		for (int j = 0;j < 3;j++)
		{
			
			printf("%d ", arr[i][j]);
		}
	}
	int sum = 0;
	int max = arr[0][0];

	for (int i = 0;i < 3;i++)
	{
		for (int j = 0;j < 3;j++)
		{
			sum += arr[i][j];
			
			if (arr[i][j] > max)
			{
				max = arr[i][j];
			}
		}
	
	}
	printf("%d", sum);
	
	return 0;
}