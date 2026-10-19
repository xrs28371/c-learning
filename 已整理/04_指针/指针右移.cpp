#define  _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
/*
定义一个包含 8 个整数的数组，输入一个整数 k，将数组中的元素向右移动 k 位。 arr[i]=arr[i+k] 进入for循环 k>len, k%len=?
使用 sizeof 计算数组长度；
编写函数：
通过指针访问和修改数组元素；
k 可能大于数组长度。
*/
void rotate(int* arr, int len, int k)
{
	int tmp[8];
	k = k % len;
	for (int i = 0; i < len;i++)
	{
		tmp[(i + k )% len] = arr[i];
	}
	for (int i = 0; i < len;i++)
	{
		arr[i] = tmp[i];
	}


}
int main()
{
	int arr[8] = { 1,2,3,4,5,6,7,8 };
	int len = sizeof(arr) / sizeof(arr[0]);
	int k=0;
	scanf("%d", &k);
	int* p = &arr[0];
	rotate(arr, len, k);
	for (int i = 0; i < len;i++)
	{
		printf("%d", arr[i]);
	}
	return 0;
}