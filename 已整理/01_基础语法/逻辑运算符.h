#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
int main()
{
	int a = 11;
	int b = 12;
	//判断关系，输出0为假，输出1为真
	printf("a>b;%d\n", a > b);
	printf("a<b;%d\n", a < b);
	printf("a>=b;%d\n", a >= b);//a>b或a=b
	printf("a<=b;%d\n", a <= b);
	printf("a!=b;%d\n", a != b);
	printf("a==b;%d\n", a == b);//比较相等，单=是赋值
	return 0;
}