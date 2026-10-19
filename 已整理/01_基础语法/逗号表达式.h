#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
int main()
{
	int a = 1;
	int b = 2;
	int c = ("a>b,a=b+10,a,b=a+1");//逗号表达式，从左向后开始计算 
	printf("c=%d\n", c);//运算符的优先级
	//当你不知道谁高谁低
	//按照自己的逻辑加括号
	return 0;
}