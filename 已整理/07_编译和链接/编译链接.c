#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include<ctype.h>
#include<string.h>
#include<assert.h>
#include<stdlib.h>
#include<limits.h>
#define PI 3.1415926//替换
//define 后面不要加分号
//防止写了两个分号
typedef int* INT_P;
int main()
{
	double a = PI * 10 * 10;
	printf("%f", a);
	return 0;
}
