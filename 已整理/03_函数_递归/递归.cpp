#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
//一个方法在执行过程中调用自身，就叫做递归
//一个完整的递归
//1.起始条件/终止条件
//2.写出递归公式


//N的阶乘
int fac(int n)
{
	if (n == 1)
	{
		return 1;
	}
	int tmp = n * fac(n - 1);
		return tmp;
}
//递和归，是两个不同的过程


int main()
{
	int ret = fac(3);
	printf("%d\n", ret);
	return 0;
}