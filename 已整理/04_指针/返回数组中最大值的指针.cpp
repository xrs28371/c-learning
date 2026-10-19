#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
//返回数组中最大值的指针
// 第一步  定义p  指向数组的第一个元素
// 第二步  遍历数组  如果当前元素大于p指向的元素 
// 则让p指向当前元素
//
int* find_max(int* arr, int len)
{
	int* max = &arr[0];
	for (int i = 0;i < len;i++)
	{
		if (arr[i] > *max)
		{
			max = &arr[i];

		}
	}
	return max;
}



int main()
{
	int arr[] = { 3, 1, 4, 1, 5, 9, 2, 6 };
	int len = sizeof(arr) / sizeof(arr[0]);
	int* p=find_max(arr,len);
	printf("Max value: %d\n", *p);


}