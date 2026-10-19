#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
int main()
{
	printf("a\n");
	printf("b\n");
	printf("c\n");//顺序结构
	//按照代码的书写运行

	//选择结构
	int x = 0;
	while(scanf("%d", &x)!=EOF)
	if (x % 2 == 1)
	{
		printf("%d is odd\n", x);//不写花括号默认一句，可读性很差
	}
	else
	{
		printf("%d 是偶数\n", x);                               
	}

	//!:逻辑取反运算符
	//&&：逻辑与运算符，就是并且的意思
	//||：逻辑或运算符，就是或者的意思，两侧至少有一个表达式为真
	
	
	
	
	
	return 0;
 }