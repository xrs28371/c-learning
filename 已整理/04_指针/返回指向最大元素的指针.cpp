#define  _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
/*返回指向最大元素的指针
int* find_max(int* arr, int len);
- 找出数组最大值，返回指向它的指针（不是返回下标，也不是返回值）
- 测试：{3,1,4,1,5,9,2} → 返回指向 9 的指针；最大值在开头/结尾也要对；{7} → 返回指向 7
- 要求：len <= 0 时返回 NULL
*/
//int*p=&arr[0]
//p与p+1比较  
int* find_max(int* arr, int len)
{
	int* max = arr;
	if (len <= 0)
	{
		return NULL;
	}
	for (int i = 0;i < len;i++)
	{
		if (*(max + i) > *max)
		{
			*max = *(max + i);
		}
	}
	return max;
}
int main()
{
	int arr[] = { 1,2,5,3,6,2,5,67,2,3,5,7,23,6,7,4,7 };
	int len = sizeof(arr) / sizeof(arr[0]);
	int* p = find_max(arr, len);
	printf("%d", *p);
	return 0;
}