#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>//数组扩大两倍，注意是原数组

int main()
{
	int arr[] = { 1,2,3,4,5 };
	int len = sizeof(arr) / sizeof(arr[0]);
	int i = 0;
	for (int i = 0;i < len;i++)
	{
		arr[i] = arr[i] * 2;
	}
	for (int i = 0;i < len;i++)
	{
		printf("%d\n", arr[i]);
	}
	return 0;
}