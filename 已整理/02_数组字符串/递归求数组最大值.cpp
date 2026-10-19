/*
输入 n 个整数，使用递归函数求出数组中的最大值。
要求：
1. 使用 sizeof 计算数组长度；
2. 编写递归函数查找最大值；
3. 记录并输出最大值及其下标；
4. 使用指针或数组下标均可，但必须使用递归。
*/
#define  _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
int findMax(int arr[], int n)
{
    if (n == 1)
    {
        return arr[0];
    }

    int max = findMax(arr, n - 1);

    if (arr[n - 1] > max)
    {
        return arr[n - 1];
    }

    return max;
}
int main()
{
	int arr[100];
	int n = 0;
	int len = sizeof(arr) / sizeof(arr[0]);
	scanf("%d", &n);
	printf("请输入%d个整数\n", n);
	for (int i = 0;i < n;i++)
	{
		scanf("%d", arr[i]);
	}
}