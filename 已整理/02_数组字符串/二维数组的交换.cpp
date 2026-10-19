#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
int main()
{
	int i = 0;
	char crr[4] = { 'a','b','c','d' };
	char arr2[] = "abcd";//遇到\0停止
	//在字符串数组中最后一个为\0
	int arr[3][3] = {
		{1,2,3},
		{4,5,6},
		{7,8,9}
	};
	printf("打印二维数组前：\n");
	for (int i = 0;i < 3; i++)
	{
		for (int j = 0;j < 3;j++)
		{
			printf("%d ", arr[i][j]);
		}
		printf("\n");
	}
	//开始交换
	//交换的核心逻辑
	for (int i = 0; i < 3;i++);
	{
		for (int j = i + 1;j < 3;j++)
		{
			int tmp = arr[i][j];
			arr[i][j] = arr[j][i];
			arr[j][i] = tmp;
		}
	}
	printf("打印交换后的数组：\n");
	for (int i = 0;i < 3; i++)
	{
		for (int j = 0;j < 3;j++)
		{
			printf("%d ", arr[i][j]);
		}
		printf("\n");
	}
	return 0;
}