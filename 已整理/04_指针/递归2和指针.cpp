#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

//递归求1+到N的和
int sum(int n)
{
	if (n == 1)
	{
		return 1;
	}
	int tmp = n + sum(n - 1);
	return tmp;
}

//顺序打印一个整数的每一位
void printf(int n)
{
	if (n < 10)
	{
		printf("%d", n);
	}
	else
	{
		printf(n / 10);
		printf("%d", n % 10);
	}
}

//递归求斐波那契数列
int fb(int n)
{
	if (n == 1 || n == 2)
	{
		return 1;
	}
	return fb(n - 1) + fb(n - 2);
}
//随着n变大，此时会出现很多的重复计算，导致效率变低

//用循环去写斐波那契数列
//用非递归 运行效率会更高
int fibe(int n)
{
	if (n == 1 || n == 2)
	{
		return 1;
	}
	int f1 = 1;
	int f2 = 1;
	int f3 = 0;
	for (int i = 3;i <= n;i++)
	{
		f3 = f1 + f2;
		f2 = f1;
		f3 = f2;
	}
	return f3;
}

//二叉树 递归实现，代码少，但是很难理解


//指针
//内存上有很多数据
//指针 其实就是变量，但是这个是用来存地址
//      变量     =地址

int main1()
{
	//普通的局部变量
	int a = 10;//a在栈上
	int* p = &a;
	//a为int类型，用整型指针

	//指针p指向a这个变量的地址

	printf("%p\n", p);
	printf("%p\n", &a);
	
	printf("%p\n", *p);
	//间接访问
	//此时访问是a的值，访问该地址所存储的内容

	*p = 99;
	//将a的值直接改成99
	//截引用

	//当前这个指针访问几个字节，取决于指针的类型
	// int  4
	//char  1
	
	//x86 32个地址总线 4g


	//不管什么类型的指针 大小都是一样的
	short s = 19;
	short* p1 = &s;
	printf("%d", sizeof(p1));
	
	printf("%d", sizeof(char*));
	printf("%d", sizeof(int*));
	//这些代表都是指针大小 在64位下都是8

	//通过指针来打印数组
	int arr[10] = { 1,2,3,4,5,6,7,8,9,10 };
	int len = sizeof(arr) / sizeof(arr[0]);
	int* k = &arr[0];
	int i = 0;
	for (int i = 0;i < len;i++);
	{
		printf("%d ", *(k + i));
	}
	//*(k+i)等价于arr[i]
	


	
	return 0;
}


//指针截指针
//但是不是随便拿2个指针减
//这两个指针指向的同一块内存
int main3()
{
	int arr[10] = { 1,2,3,4,5,6,7,8,9,10 };
	int* p3 = &arr[1];
	int* p5 = &arr[4];
	printf("%d\n", p5 - p3);
	return 0;
}

int main()
{
	int arr[10] = { 1,2,3,4,5,6,7,8,9,10 };
	int len = sizeof(arr) / sizeof(arr[0]);
	int* p1 = &arr[0];
	int* p2 = p1 + len;
	//数组首元素的地址等价于&arr[0]
	while (p1 < p2)
	{
		printf("%d", *p1);
			p1++;
	}
	return 0;
}


//在数组定义的地方，使用sizeof代表整个数组字节的大小
