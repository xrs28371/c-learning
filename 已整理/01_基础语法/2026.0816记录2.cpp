#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>

int main()
{/*
	short a = 10;//短整型short   长整型long，更长整型longlong
	short b = 20;
	//格式化输出
	printf("%d,%d\n", a, b);
	return 0;*/
/*
	float money = 9.9f;//单精度浮点数，小数点后六位，手动添加标记
	printf("%f\n", money);
	//双精度浮点数  小数点后十五位
	double d = 12.5;
	printf("%lf\n", d);*/

	bool flg = true;
	if (flg)
	{
		//如果真的，就执行这里，输出哈哈哈
		printf("哈哈哈\n");
	 }
	else
	{
		printf("嘿嘿嘿\n");
	}
	//并且在c语言中，0是假，非0是真
	int flg2=1
		if (flg2)
		{

	
		}
	 return 0;
	 /*000 001 110 000 110 101
	  0       1     6    0      6     5 八进制 016065  0~7
	  0001 1100 0011 0101 十六进制 abcdef
	  1          12 c  3     5                1c35 */


	 int a1 = 0100;//编译器看到开头为0，就知道这是一个八进制
	 int a2 = 0x40;//编译器看到开头为0，就知道这是一个十六进制
	 printf ("%d\n",a1,a2)

/*  原码，反码，补码
* 原码   符号位和数值位
* 以八位二进制举例：0000 1010
* 0  0  0  0  1  0  1  0
* 只对有符号来说：
* 有符号：正，负，数
* 如上，第一位0，代表了正数，如果第一位1，代表了负数
* +12的原码为：0000 1100
* -12的原码为：1000 1100
* signed int a=-10;此时第一位为符号位
* unsigned int a=-10;此时第一位为数值位，此时代表了数值为137
* 










*/



}