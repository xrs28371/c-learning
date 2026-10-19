#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include<math.h>



//sqrt平方根，pow n的x次方
//库函数：在c标准已经帮你实现好的一批函数
// 引入头文件


//自定义函数
//格式
//ret_type是函数返回类型
//fun_name是函数名
//括号中放的是形式参数
//{}中是函数体
//ret_type fun_name

    //计算两个整数相加的功能
	int add(int a, int b)
	{
		int sum = a + b;
		return sum;//传递sum的值，，return代表结束
	}

	//求一个整数n的阶乘
	int xrs(int n)
	{
		int ret = 1;
		for (int i = 1;i <= n;i++)
		{
			ret *= i;
		}
		return ret;
	}

	//2个参数
	//都是整形
	//返回值是否存在，存在用相同类型接受
	//按照值传递
	
	//从上往下编译，自定义函数要在前面
	
	int xrs(int n);
	//如果写在后面要在前面写出声明
	
	//交换两个整数
	//但是return只能返回一个值
	//需要引入指针来解决
	
	
	
	int main()
	{
		int m = 1;
		int n = 4;
		add(m, n);
		printf("%d\n", add(m, n));
		

		int a = 5;
		int b = xrs(5);
		printf("%d\n", b);
		return 0;
	}


	//关于调试
	//使用打断点的方式，鼠标左键最左边
	//或者F9

	//通过数组来定义函数
	//无返回值类型  
	//打印数组
	//c语言不能返回数组
	void printf_arr(int arr[], int len)
	{
		for (int i = 0;i < len;i++)
		{
			printf("%d\n", arr[i]);
		}
	}
	
	//嵌套调用函数
	void fac(int n)
	{
		int ret = 1;
		for (int i = 0;i <= n;i++)
		{
			ret *= i;
		}
		printf("%d\n", ret);
	}
	//一个数的阶乘

	//n个数阶乘的相加
	int fac_sum(int n)
	{
		int sum = 0;
		for (int i = 0;i <= n;i++)
		{
			sum = xrs(i) + sum;
		}
		return 0;
	}

	//链式调用,利用返回值一环套一环