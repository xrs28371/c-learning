#define  _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
/*
输入 5 个整数,编写函数swap
使用指针交换数组中的最大值和最小值；
输出交换前后的数组；
输出最大值和最小值交换后的位置。
*/
void swap(int *px,int*py)
{
	int tmp = *px;
	*px = *py;
	*py = tmp;
}

int main()
{
	int arr[5];
	int n = 5;

	for (int i = 0;i < n;i++)
	{
		scanf("%d", &arr[i]);
	}
	
	int max = 0;
	int min = 0;

	for (int i = 0;i < n;i++)
	{
		if (arr[i] > arr[max])
		{
			max = i;
		}
		if(arr[i] < arr[min])
		{
			min = i;
		}
	}

	printf("交换前：");
	for (int i = 0; i < 5; i++)
	{
		printf("%d ", arr[i]);
	}

	swap(&arr[max], &arr[min]);

	printf("交换后：");
	for (int i = 0; i < 5; i++)
	{
		printf("%d ", arr[i]);
	}
	printf("%d", max);
	printf("%d", min);
	return 0;
}