
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include"fuc.h"
//都是引入头文件                                                                                                                                
//双引号是自定义的头文件
//<>是系统带的头文件


void test()
{
	static int i = 0;//静态的局部变量，加了static会改变生命周期，这里会不断累加
	i++;
	printf("%d ", i);
}


int main1()
{
	for (int i = 0;i < 5;i++)
	{
		test();
	}
	return 0;
}



//当一个全局变量被static修饰，改变作用域，只能在当前的.c使用

//栈区，堆区，静态区
//栈区：局部变量，函数参数
//堆区：动态内存管理
//静态区：全局变量，静态变量


int main()
{
	printf("%d\n", add(1, 2));
	return 0;
}

//如果你不想让这个函数在别的文件中调用就在前面加上static


//.h中 我们会写函数的声明
//.c中 我们会写函数的实现
//使用的源文件 我们直接调用


//栈区使用是从高地址到低地址
// 这个是32位情况下
// 在64位情况下是由低到高
//定义a和b之间会空出两个位置
//数组内部由低到高
