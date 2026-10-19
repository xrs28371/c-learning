//指针数组
//是数组还是指针？  从概念上理解是数组
//存放指针的数组
//类似
//整型数组   存放整型的数组
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
//定义指针数组
void printf_arr(int* arr[], int len)
{
	for (int i = 0;i < len;i++)
	{
		printf("%p ", *arr[i]);
	}
	printf("\n");
}

//用二级指针来打印
void print(int** arr, int len)
{
	for (int i = 0;i < len;i++)
	{
		printf("%p ", **arr);
		arr++;
	}
	printf("\n");
}



void printf_arr(int (*p)[3], int row, int sol)
{
	for (int i = 0;i < row;i++)
	{
		for (int j = 0;j < sol;j++)
		{
			printf("%d ",*((*p)+i)+j);
		}
	}
}



int main1()
{
	int a = 10;
	int b = 20;
	int c = 30;

	int* p1 = &a;
	int* p2 = &b;
	int* p3 = &c;

	int* arr[3] = { p1,p2,p3 };
	int len = sizeof(arr) / sizeof(arr[0]);
	printf_arr(arr, len);
	printf("\n");
	print(arr, len);
	return 0;
}


//用二级指针来打印二维数组
int main2()
{
	int arr[2][3] = { 1,2,3,4,5,6 };
	int ret = arr[0][1];
	int(*p)[3] = &arr[0];
	//先通过行再通过列
	//数组名代表数组首元素的地址
	//&arr[0]  整个一维数组的地址
	//
	printf_arr(arr, 2, 3);
	printf("%d\n", ret);
	printf("%d\n", *(arr[1] + 2));
	printf("%d\n", *(*(arr + 1) + 2));
}