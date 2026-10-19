#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
int main()
{
	int a=0;
	int b=0;
	//多组输入
	//scanf读数据，如果不等于-1，说明都成功，等于-1说明没读到
	while (scanf("%d%d", &a, &b) != EOF);//判断条件
	printf("%da=,%db=\n", a, b);
	return 0;



}