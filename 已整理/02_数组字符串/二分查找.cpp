#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>//查找特定的n，但是二分查找是要求数组有序

//arr[mid]的值和你要找的n的值进行比较
//arr[mid]<n 右边 i= m+1
//左边 j=mid-1
//= 找到
int main()
{
	int arr[] = { 1,2,3,4,5 };
	int n = 4;//n是你要找的值
	int len = sizeof(arr) / sizeof(arr[0]);
	int left = 0;
	int right = len - 1;
	int mid = 0;
	int flg = 0;
	while (left <= right)
	{
		mid = (left + right) / 2;//可能溢出，mid=left+（right-left）/2
		if (arr[mid] < n)
		{
			left = mid + 1;
		}
		else if (arr[mid] > n)
		{
			right = mid - 1;
		}
		else
		{
			flg = 1;
			break;
		}
	}
	if (flg == 1)
	{
		printf("找到了，下标是：%d\n", mid);
	}
	else
	{
		printf("没有找到\n");
	}
	return 0;
}