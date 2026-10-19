#define  _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
/*
定义一个包含 10 个整数的数组，使用 sizeof 计算数组长度。
要求：
1. 使用指针遍历数组；
2. 统计偶数和奇数的个数；
3. 统计正数、负数和 0 的个数；void
4. 计算所有元素的平均值。int sum/len
要求至少使用一个指针完成遍历。
*/
int main()
{
	int arr[10] = { 1,2,3,4,5,6,7,8,9,10 };
	int len = sizeof(arr) / sizeof(arr[0]);
	int* p = &arr[0];
	for (int i = 0;i < len;i++)
	{
		printf("%d ", *(p + i));
	}
	int even = 0;//偶数
	int odd = 0;//奇数
	int positive = 0;//正数
	int negative = 0;//负数
	int zero = 0;//0的个数
	int ave = 0;//平均值
	
	for (int i = 0;i < len;i++)
	{
		if (arr[i] % 2 == 0)
		{
			even++;
		}
		else
		{
			odd++;
		}
	}

	for (int i = 0;i < len;i++)
	{
		if (arr[i] > 0)
		{
			positive++;
		}
		else if (arr[i] < 0)
		{
			negative++;
		}
		else
		{
			zero++;
		}
	}

	int sum = 0;
	for (int i = 0;i < len;i++)
	{
		sum = arr[i] + sum;
	}
	ave = sum / len;
	printf("\n");
	printf("正数的个数%d\n", positive);
	printf("负数的个数%d\n", negative);
	printf("偶数的个数%d\n", even);
	printf("奇数的个数%d\n", odd);
	printf("0的个数%d\n", zero);
	printf("平均值%d\n", ave);

	return 0;
}
