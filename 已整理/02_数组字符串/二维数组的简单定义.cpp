#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
//二维数组

//不够补0
int main()
{
	int arr[2][3];
	int arr2[2][3] = { 1,2,3,4,5,6 };
	int arr3[2][3] = { {1,2,3},{4,5,6 } };//这里里面花括号可以省略
	int arr4[2][3] = { {1,2 },{4} };//不够补0
	int arr5[][3] = { 1,2,3,4,5,6 };//可以省略行但是不能省略列
	//arr[]里面只能为常量

	for (int i = 0;i < 2;i++)
	{
		for (int j = 0;j < 3;j++)
		{
			printf("%d ", arr2[i][j]);
		}
		printf("\n");
	}
}

