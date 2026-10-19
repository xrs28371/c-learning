#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
//函数指针
//找到函数的地址
void test()
{
	printf("hehe\n");
}
int add(int x, int y)
{
	return x + y;

}
int main()
{
	//当前需要定义一个指针，这个指针变量可以保存函数的地址
	//指向函数的指针就是    函数指针
	void(*p)() = &test;
	{
		printf("hehe\n");
	}
	//  函数类型 指针 参数 地址
	printf("&test:%p \n", p);

	int (*p1)(int a, int b) = &add;
	// 存了函数的地址
	add(111, 222);
	int ret = (*p1)(1, 2);
	printf("%p\n", p1);
	printf("%d \n", ret);


	//函数指针数组怎么写    数组当中  存放的是函数指针
	//要声明一个数组，里面装 3 个"指向 int f(int, int) 的函数指针"
	//int(*arr[3])(int,int)={函数，函数，函数}


}