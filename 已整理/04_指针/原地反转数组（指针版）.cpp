#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
//把数组原地反转，不允许开第二个数组
//{1,2,3,4,5}  {5,4,3,2,1}
//int *p1=&arr[0]   int *p2=&arr[len]
//p1++  p2--     p1==p2
void reverse(int* arr, int len)
{
	int* p1 = &arr[0];
	int* p2 = &arr[len-1];
	while(p1<p2)//防止重复的交换
	{
		int tmp = *p1;
		*p1 = *p2;
		*p2 = tmp;
		p1++;
		p2--;
	}
	
}
int main()
{
	int arr[5] = { 1,2,3,4,5 };
	int len = sizeof(arr) / sizeof(arr[0]);
	printf("交换前\n");
	for (int i = 0;i < len;i++)
	{
		printf("%d ", arr[i]);
	}
	printf("\n");
	reverse(arr, len);
	printf("交换后\n");
	for (int i = 0;i < len;i++)
	{
		printf("%d ", arr[i]);
	}
	return 0;
}