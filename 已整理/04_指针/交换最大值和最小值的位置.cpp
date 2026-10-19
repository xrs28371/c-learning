#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
/*
在数组里找到最大值和最小值所在的位置
把这两个位置的值互换
*/
void swap_min_max(int* arr, int len)
{
	int* p1 = arr + 1;
	int* p2 = arr;//存最大值
	int* p3 = arr;//存最小值
	if (arr == NULL || len <= 0)
	{
		return;
	}
	while (p1 < arr + len)
	{
		if (*p1 > *p2)
		{
			p2 = p1;

		}
		if (*p1 < *p3)
		{
			p3 = p1;
		}
             p1++;
		}
	int temp = *p3;
	*p3 = *p2;
	*p2 = temp;
}
int main()
{
	int arr[] = { 3, 1, 4, 1, 5 };
	int len = sizeof(arr) / sizeof(arr[0]);
	swap_min_max(arr, len);

	printf("交换后的数组：");

	for (int i = 0; i < len; i++)
	{
		printf("%d ", arr[i]);
	}
	return 0;


}