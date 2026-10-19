#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
//void print_col_sums(int (*p)[4], int rows);
//- 对每一列，把这一列所有行的数加起来打印
//- 测试：arr[3][4] = { {1,2,3,4},{5,6,7,8},{9,10,11,12} } →第 0 列和 = 15   (1 + 5 + 9)
//第 1 列和 = 18   (2 + 6 + 10)
//第 2 列和 = 21
//第 3 列和 = 24
void print_col_sums(int (*p)[4], int rows)
{
	for (int i = 0;i < 4;i++)
	{
		int sum = 0;
		for (int j = 0;j< rows;j++)
		{
			sum += p[j][i];
		}
		printf("第%d列和 = %d\n", i, sum);
	}
}
int main()
{
	int arr[3][4] = { {1,2,3,4},{5,6,7,8},{9,10,11,12} };
	int (*p)[4] = arr;
	int rows = sizeof(arr)/sizeof(arr[0]);
	print_col_sums(arr, rows);
}