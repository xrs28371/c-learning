//复习，signed ，有符号，可以表示正数，也可以表示负数
//无符号，unsigned,当前这个类型，只能表示正数
//浮点类型            小数不是准确的数字
//float.单精度
//double ,双精度
//long double,更高精度

//原码 针对了二进制，12，1100
//八位二进制为例，0000 1100
// 在符号位：0为正数，1是负数

//-1 原码：1000 0001
//反码 结论：对于正数来说原 反 补 都是一样的

//对于负数来说，-12 1000 1100
//反码：1111 0011，符号位不变，其他位取反
//负数在内存里面，存储就是补码，补码等于反码+1

// 计算机为什么统一存储补码？？
//它让硬件最简单、成本最低、运算最快
//加减法统一，一套电路搞定
// 只有一个零
// 多表示一个负数	

/*bit 比特位
* 一个比特位只能放一个二进制数据
*byte 字节 
* 一个字节=八个比特位
* 1024byte=1KB
* KB-GB-TB-PB 往后都是以1024为单位
*/

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include<stdbool.h>
int global = 10;
int main()
{ 
	printf("%zu\n", sizeof(char));//1
	printf("%zu\n", sizeof(bool));//1
	printf("%zu\n", sizeof(short));//2
	printf("%zu\n", sizeof(int));//4
	printf("%zu\n", sizeof(long));//4
	printf("%zu\n", sizeof(long long));//8
	printf("%zu\n", sizeof(float));//4
	printf("%zu\n", sizeof(double));//8
	printf("%zu\n", sizeof( long double));//%zu是表示一个整数
    short a = 10;//两个字节
	int b = 10;//四个字节
	char ch = 10;//
		//实际占用内存的大小是不一样的
	unsigned char e = 127;
	unsigned char f = e + 1;
	printf("%d\n", f);
	//变量与常量
	//类型 变量=数据；表达式，如上为局部变量
	
	//局部变量：函数内部{}找花括号
	
	//全局变量;在大括号的外面。在实际开发过程中基本不用
	
	//作用域：花括号内部为局部变量的使用范围
	
	//全局变量的作用域为整个工程
	//生命周期：出生到死亡
	//创建到销毁
	//全局 运行创建，结束销毁
	
	//局部 进入花括号创建，出了花括号销毁
	//局部变量有优先使用权，就近原则使用，是在名字相同的时候体现
	//局部变量，函数参数，栈区
	
	
	//动态内存，堆区
	//全局变量。静态区
	//通过不同的数据类型定义不同的变量
	
	
	//在c语言系统在不同的系统，数据类型大小不同
	float g = 16.5;
	int t = (int)g;//强制类型转化，同时可能会丢失数据
	printf("%d\n", t);
	


	//占位符
	int u = 7;
	printf("there are %d apples\n", u);

	printf("%s will come\n","蛋");//给字符串占位置

	//将来由用户输入，s用来给蛋占位置

	/*字符串的含义
	* %o 八进制整数
	* %p 指针（用来打印地址）
	* %u 无符号整数 unsigned int
	* %x 十六进制整数
	* %zu size_t类型
	*/
	
	printf("%5d\n", 1234);//限定占位符的最小宽度，最小的宽度是5
	//左对齐，左边补空格
	
	
	printf("%-5d\n", 678);//右对齐 右边补空格，一共占五个
	
	printf("edsf\n");
	
	printf("Number is %.2f\n", 0.4);
	//限定小数后两位
	
	printf("%8.2f\n", 0.1);

	int score = 0;//初始化
	printf("请输入成绩");
	scanf("%d",& score);
	printf("成绩是：%d\n", score);
	//scanf里面有什么就要输出什么
	//a，b
	//1，2
	//与printf不同
	return 0;
}
	