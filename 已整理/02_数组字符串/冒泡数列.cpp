#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>//冒泡排序
//arr[j]>arr[j+1]交换
//相反不换，与更下一位比较，再决定交换不交换
//n个数据比较n-1次
//第一个问题，趟数
//len-1判断
int main()
{
	int arr[] = { 5,42,2,54,6,99 };
	int i = 0;
	int len = sizeof(arr) / sizeof(arr[0]);
	int j = len - 1;
	//打印排序前的数组
	for (int i = 0;i < len;i++)
	{
		printf("%d ", arr[i]);
	}
	//冒泡序列开始交换
	//首先表示进行的次数
	
	int flg = 0;
	
	for (int i = 0;i < j;i++)
	{
		for (int j = 0;j < len - 1 - i;j++)
		{
			flg = 0;//整体优化
			//此时开始交换
			if (arr[j] > arr[j+1])
			{
				int tmp = arr[j];
				arr[j] = arr[j+1];
				arr[j+1] = tmp;
				flg = 1;
			}
			if (flg == 0)
			{
				break;
			}
		}
	}
	for (int i = 0;i < len;i++)
	{
		printf("%d ", arr[i]);
	}
	return 0;
}