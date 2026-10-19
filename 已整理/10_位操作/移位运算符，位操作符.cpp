#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
int main()
{
	int n = 10;
	int num = n << 1;
	printf("n=%d\n", n);
	printf("num=%d\n", num);
	//<<左移符号，向左移动一个比特位，但是可能倒是符号的改变，产生歧义

	int a = 5;
	int b = a >> 1;//向右边移动一个比特位                   b>>=1,b=b>>1
	printf("a=%d\n", a);
	printf("b=%d\n", b);//左边补的是符号位，0补0，1补1，-1很特殊，怎么移动都是-1
	//对于负数来说，向下取整
	
	int x = 6;
	int y = 8;
	int z = x & y;
	printf("z=%d\n", z);
	//按位与，有0取0，都为1取1，是在对应的比特位上
	//按位或，有1取1，都为0取0，也是在对应比特位
	//符号位符号|



	//按位取反~，0变1，1变0
	
	
	
	return 0;
}