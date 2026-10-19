#define  _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include<assert.h>
#include<string.h>
int main1()
{
	const int a = 10;
	const int* p = &a;
	//限制访问内存，防止通过指针p解引用来修改内存中的值
	return 0;
}
int main2() 
{
	int a = 10;
	const int* p = &a;
	// const int * const p
	//如果这么修饰都无法改变

	//*p=99;   error    此时无法解引用p
	int b = 20;
	p = &b;
	printf("%d", *p);
	//虽然无法解引用p的值，但是可以读取p的值
	return 0;
}

// 当希望某个数据只读，我们就用const来修饰


//野指针

//第一种成因，指针未初始化
int main3()
{
	int* p = NULL;//意思是给一个0号地址，无法使用的
	// 但是NULL中有保留区，无法间接访问
	int a = 0;
	p = &a;
	*p = 100;
	
	//*p = 100;//非法访问内存

	printf("%d\n", *p);
	return 0;
}

//第二种成因：越界访问
int main4()
{
	int arr[10] = { 0 };
	int* p = &arr[0];
	int i = 0;
	int len = sizeof(arr) / sizeof(arr[0]);
	for (int i = 0;i < 11;i++)//出现了超越定义的数组范围
	{
		*(p++) = i;
		printf("%d ", *(p + i));
	}
	return 0;
}
//不管通过指针还是下标都不能越界访问


//指针指向的空间被释放
int* test()
{
	int n = 0;//n是局部变量,生命周期是函数开始到函数的结束
	return &n;
}
int main5()
{
	int* p = test();//此时局部变量n的地址已经被销毁，无法找到n，但是也有可能找到n的地址
	*p = 100;
	printf("%d\n", *p);
}

//assert 断言 
//一旦断言失败，程序将不再继续执行
// 断言失败后输出的信息，详细定位
// 同时在release下不起任何作用只在debug下起作用
int main6()
{
	int a = 11;
	assert(a == 10);
	printf("%d===",a);
	return 0;
}

//指针的使用和传地址作用
//streln  专门去求字符串的长度  可以理解为字符的个数
//%zu 来打印无符号的返回类型


size_t my - streln(const char* p)
{
	size_t count = 0;
	while (*p != '\0')
	{
		count++;
		p++;
	}
	return count;
}


int main7()
{
	char* str = "hello";//指向本身是常量无法改变
	//如果改成数组之后就可以改变了
	


	char str2[] = "hello";
	size_t len = my - streln(str);//数组的名称就是指向首元素的地址
	printf("%zu ", len);
	return 0;
} 

//不同类型的指针解引用的能力也是不同的
int main8()
{
	int arr[] = { 1,2,3,4,5 };
	short* p = (short*)arr;
	//强制类型的转换导致指针p能够指向的字节数量变小
	//原来是四个变成两个
	for (int i = 0;i < 4;i++)
	{
		*(p + i) = 0;//导致只能改变数组前两个数据
	}
	for (int i = 0;i < 5;i++)
	{
		printf("%d ", arr[i]);//此时输出的结果会变成0，0，3，4，5
	}
	return 0;
}


