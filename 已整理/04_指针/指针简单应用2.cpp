#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
//输入一个正整数 n，使用递归计算它各位数字的和
// /10 %10   最后一位
int digitSum(int n)
{
	if (n < 10)
	{
		return n;
	}
	return n % 10 + digitSum(n / 10);
}
int main()
{
	int n = 0;
	scanf("%d", &n);
	digitSum(n);
	printf("%d\n", digitSum(n));
	return 0;
}