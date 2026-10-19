#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

//输入一个正整数n
//输入n个整数
//冒泡序列
//降序排列


int main()
{
	int arr[100];//定义一个数组
	int n = 0;
	int i = 0;
	int flg = 0;
	printf("请输入一个正整数：\n");
	scanf("%d", &n);

	printf("请输入%d个正整数\n", n);
	for (int i = 0;i < n;i++)
	{
		scanf("%d", &arr[i]);
	}
	//输入工作完成

	//冒泡排序
	for (int i = 0;i < n;i++)
	{
		int flg = 0;
		for (int j = 0;j < n - 1 - i;j++)
		{
			if (arr[j + 1] > arr[j])
			{
				int tmp = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = tmp;
				flg = 1;
			}
		}
		if (flg == 0)break;
	}
	//排序完成

	//输出 倒序
	printf("最后输出为");
	for (int i = 0;i < n;i++)
	{
		printf("%d ", arr[i]);
	}
	return 0;
}