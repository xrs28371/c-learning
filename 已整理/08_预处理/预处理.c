#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include<ctype.h>
#include<string.h>
#include<assert.h>
#include<stdlib.h>
#include<limits.h>
//用define来定义宏
//示例
#define SQUARE(x) x*x
//只要出现SQUARE（x）就替换x*x
//与函数不同
//函数是要去单独开辟空间
//而这里的宏这是起到了替换的作用
//千万不要加空格
#define SQUARE2(x) ((x)+(x))
//要记住运算符的优先级
int main1()
{
	int a = SQUARE(5);//替换成了x*x
	printf("%d\n", a);
	return 0;

}




//带着副作用的宏
//? :
//这是三目运算符
//返回两个数据中的最大值
#define MAX(a,b) ((a)>(b)?(a):(b))
int main2()
{
	int x = 5;
	int y = 8;
	int z =MAX(x++, y++);
	printf("x=%d y=%d z=%d\n", x, y, z);//此时会输出什么呢？？ x=6 y=10 z=9
	// int z =((x++)>(y++)?(x++)(y++))
	// x>y ?5>8
	// x++ y++ x=6 y=9
	// z=y++ z=9 y=10
	//简单来说z就是等于较大的数字自增一次 然后本身自增两次
	return 0;

}


//宏的替换规则
//1.在调用宏时，首先对参数进行检查，看看是否包含任何由#define定义的符号。如果是，它们首先被替换。
//2.替换文本随后被插入到程序中原来文本的位置。对于宏，参数名被他们的值所替换。
//3.最后，再次对结果文件进行扫描，看看它是否包含任何由#define定义的符号。如果是，就重复上述处理过程。

//示例
#define N 100
#define ADD(a,b) ((a)+(b))
#define DOUBLE(x) ADD(x,x)
int main3()
{
	int result = DOUBLE(N);
	printf("%d\n", result);
	return 0;
}

//整个过程是怎么进行拆解的
//原码：
//DOUBLE(N)
//参数替换
//DOUBLE(100)
//宏体替换
//ADD(100,100)
//再次扫描
//((100)+(100))

//注意 宏不能出现递归 在宏定义里面不能再次展开他自己
//同时字符串里面的常量也是不会被搜索的


//宏函数的对比
//例如上面定义的找到最大值
//函数如下
int max_max(int a, int b)
{
	return a > b ? a : b;
}
//宏优势
//速度快
//劣势
/*
1.每次使用宏的时候，一份宏定义的代码将插入到程序中。除非宏比较短，否则可能大幅度增加程序的长度。
2.宏是没法调试的。
3.宏由于类型无关，也就不够严谨。
4.宏可能会带来运算符优先级的问题，导致程容易出现错。
*/

//续航符
#define MALLOC(num, type) \
(type *)malloc(num * sizeof(type))
//等同于
//#define MALLOC(num, type) (type *)malloc(num * sizeof(type))
int main4()
{
	int* p = MALLOC(10, int);
	//(int *）malloc(10*sizeof(int))
	return 0;
}
//此时就能传递类型了


//运算符
//运算符将宏的一个参数转换为字符串字面量。它仅允许出现在带参数的宏的替换列表中
//运算符所执行的操作可以理解为"字符串化”

//当我们有 int a =10  我们想要去打印出：the value of a is 10
#define PRINT(n) printf("the value of "#n"is %d",n);
int main5()
{
	int a = 10;
	PRINT(a);//#a就会被转化为"a"
	return 0;
}

//运算符
//##
/*
##可以把位于它两边的符号合成一个符号，它允许宏定义从分离的文本片段创建标识符。
##被称为记号粘合
这样的连接必须产生一个合法的标识符。否则其结果就是未定义的。*/
#define DENERIC_MAX(type)\
type type##_max(type x,type y)\
{               \
    return (x>y?x:y);\
}

//首先定义在main函数的外面
DENERIC_MAX(int);
DENERIC_MAX(float);
int main6()
{
	int m = int_max(2, 3);
	printf("%d\n", m);
	return 0;
}

//函数和宏使用语法相似
//所以一般函数名字小写
//宏定义大写

//#undef 用于移除一个宏定义
//示例
#define SIZE 10
//#undef SIZE       相当于不认识size了
int main7()
{
	int size = SIZE;
	printf("%d\n", size);
	return 0;
}

//行命令
//无法在vs上编译
//更适合linux

//条件编译
//示例
#define _DEBUG_
int main8()
{
	int i = 0;
	int arr[10] = { 0 };
	for (int i = 0;i < 10;i++)
	{
		arr[i] = i;
#ifdef _DEBUG_
		printf("%d\n", arr[i]);//为了观察数组是否成功赋值
#endif//_DEBUG_
	}
	return 0;
}
	/*
#if 常量表达式
#endif
//常量表达式由预处理器求值。
如:
#defineDEBUG工
#if
DEBUG
#endif
2.多个分支的条件编译
#if常量表达式
#elif 常量表达式
11..
#else
#endif
3.判断是否被定义
#if defined(symbol)#ifdefIsymbol
#if Idefined(symbol)
#ifndef symbol
4.嵌套指令
#ifdef OPTION1
#if defined(Ts_UNIX)
unix_version_optioni();
#endif
#ifdef OPTION2
unix_version_option2();
#endif
#elif defined(0s_MSD0s)
#ifdef OPTION2
msdos_version_option2();
#endif
#endif
*/

//可以使用 #if 0   #endif  达到类似注释效果

//头文件
//头文件被包含的方式
//#include "filename." 这种双引号
//先在源文件所在目录下查找，如果该头文件未找到，编译器就像查找库函数头文件一样在标准位置查找头文件。
//如果找不到就提示编译错误

//#pragma once  防止头文件的多次引用
#ifndef  TEST_H  //TEST_H 可以随意更改
#define TEST_H_
//头文件的内容
#endif // TEST_H

//头文件中的ifndef/define/endif是干什么用的
/*
#ifndef (if not defined)：检查后面的宏是否未被定义。如果未定义，则编译后面的代码直到遇到 #endif。

#define：定义一个宏。通常在 #ifndef 检查通过后立即定义这个宏，以此标记该头文件已被包含。

#endif：结束条件编译块。*/
