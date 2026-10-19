#define  _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
int main()
{
	int x = 3 % 2;//3模2.    3除2的余数 
	int y = -3 % 2; //余数是正数还是负数取决于第一个操作数
	int z = 3 % -2;
	int c = -3 % -2; 
	printf("%d\n", 3 % 2);
	printf("%d\n", -3 % 2);
	printf("%d\n", 3 % -2);
	printf("%d\n", -3 % -2);
	return 0;

}