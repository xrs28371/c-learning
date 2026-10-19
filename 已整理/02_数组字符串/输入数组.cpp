#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main()
{
	int arr[5];
	for (int i = 0;i < 5;i++)
	{
		scanf("%d ", &arr[i]);//空格一定要加不然无法识别
	}
	printf("打印数据：\n");
	return 0;
}