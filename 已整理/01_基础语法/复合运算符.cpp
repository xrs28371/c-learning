#define  _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
int main()
{
	int a = 10;
	a += 3;//a=a+3,其他类似雷同
	printf("%d\n", a);//这些都是双目操作符
	
	int b = 1;
	b++;//后置++，自增1
	printf("%d\n", b);
	
	int c = 2;
	++c;//前置++，自增1
	printf("%d\n", c);
	
	
	
	//前置++与后置++的区别
	int x = 5;
	int y = x++;//y=x,x++,先使用，后加加
	printf("x=%d\n", x);//6
	printf("y=%d\n", y);//5
	
	
	int e = 6;
	int f = ++e;//先加加，后使用，e++,e=f
	printf("e=%d\n",e );//7
	printf("f=%d\n",f );//7

	//总结
	//单独使用没区别
	//在赋值的情况下不一样
	//前置减减也是一样的

	
	
	
	
	return 0;
}