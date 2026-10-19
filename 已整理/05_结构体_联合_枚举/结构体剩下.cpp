#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include<ctype.h>
#include<string.h>
#include<assert.h>
//结构体内存对齐
// 第一个成员对齐到与起始位置偏移量为0的地址
// 第二个开始 要对齐到某个对齐数的整数倍的地址处
// 对齐数 在vs中默认值为8
//用浪费空间来换取时间的操作
struct S1
{
	char a;// 1  8   1    
	int c;// 4   8  4     
	char b;//1   8   1     
};// 最后为12
struct S2
{
	char p;// 1  8   1
	char p1;//1  8   1
	int a;//  4    8   4
};// 为8 
struct S3 
{
	double a;
	char s;
	int i;
};
struct S4
{
	char c1;
	struct S3 se3;
	double w;
};
//如果嵌套结构体 对齐到成员最大对齐数的整数倍
//结构体整体大小是所有最大对齐数的整数倍数  恰好是32
int main1()
{
	printf("%zu\n", sizeof(struct S1));
	printf("%zu\n", sizeof(struct S2));
	printf("%zu\n", sizeof(struct S3));
	printf("%zu\n", sizeof(struct S4));
	return 0;
	//为什么前一个和后一个占用的空间不一样呢
	//结构体第一个成员同样对齐到为0的地方
	
}
//内存对齐主要是为了提升速度和兼容硬件平台
//提升cpu


//修改默认对齐数
#pragma pack(4)
struct s
{
	char r;     //     1  4   1   01
	int s;      //   4   4   4     4567
	char u;     //    1  4   1     
};
#pragma pack()
//恢复默认对齐数
int main()
{
	printf("%zu\n", sizeof(struct s));
	return 0;
}