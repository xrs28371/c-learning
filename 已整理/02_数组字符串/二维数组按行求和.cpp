#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
/*
p 是行指针，指向一个 rows 行、4 列的二维数组
对每一行，把这一行的 4 个数加起来，打印出来
建议打印格式：第 0 行和 = 10
*/
void print_row_sums(int (*p)[4], int rows)
{
	int sum;
	for (int i = 0;i < rows;i++)
	{
		sum = 0;
		for (int j = 0;j < 4;j++)
		sum += p[i][j];
		printf("第 %d 行和 = %d\n", i, sum);
		
	}
}
int main()
{
	int arr[3][4] = { {1,2,3,4}, {5,6,7,8}, {9,10,11,12} };
	int (*p)[4] = arr;
	int len = sizeof(arr) / sizeof(arr[0][0]);
	int rows = 3;
	print_row_sums( arr,  rows);
	
}