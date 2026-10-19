#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include<ctype.h>
#include<string.h>
#include<assert.h>
//strstr   从头开始找字符串
//查找str2指向的字符串在str1首次出现的位置
int main1()
{
	const char* str1 = "abcdhelloworld";
	const char* str2 = "hello";
	//此时不单单打印hello hello后面的也会被打印 

	//KMP算法
	//本质上表示的就是字符串的查找
	const char *ret=strstr(str1,str2);
	printf("%s\n", ret);
}
//string.h   中还有很多这样的函数保持学习


void cheak()
{
	int a = 0x11223344;
	char* p = (char*)&a;
	if (*p == 0x44)
	{
		printf("小端机器\n");
	}
	else
	{
		printf("大端机器\n");
	}
}


//大小端字节序
int main2()
{
	int a = 0x11223344;
	printf("%x\n", a);
	cheak();
	return 0;
	//上面的数据到底是怎么存进去的
	//小端机器
	//低地址放地数据    
	//高地址放高数据
	//大段机器就相反  网络字节序

}
//memcpy  
//来自<string.h>
//类型是 void*
int main3()
{
	int a = 10;
	int* p1 = &a;
	printf("%d", *p1);
	  
	void* p2 = &a;
	int* pp = (int*)p2;
	//void可以接受任何类型的指针但是不能打印  不同类型

}
//memcpy是完成内存拷贝的 不关注内存中存放的数据是啥
//如果src和dst有任何重叠的 复制的结果时未知的
int main4()
{
	int arr1[10] = { 1,2,3,4,5,6,7,8,9,10 };
	int arr2[20] = { 0 };
	memcpy(arr2, arr1, 20);
	// 要拷贝到的地方  要拷贝的东西  拷贝的字节数
	for (int i = 0;i<20;i++)
	{
		printf("%d ", arr2[i]);
	}
	return 0;
}
//此时memmove 是允许的

//memset  设置内存的 
int main5()
{
	char str[] = "hello world";
	memset(str, 'x', 6);
	//  目标数组  修改的值   修改的字节数量  
	//而且memset多用于修改char类型的 因为修改的是每一个字节
	printf("%s", str);
	return 0;
}

//memcmp
// 内存的比较

int main6()
{
	char buffer1[] = "DWgaOtP12df0";
	char buffer2[] = "DWGAOTP12DF0";
	int n;
	n = memcmp(buffer1, buffer2, sizeof(buffer1));
	//比较b1和b2指针指向的位置开始 向后sizeof个字节

	if (n > 0)
	{
		printf("'%s'大于'%s'.\n", buffer1, buffer2);
	}
	else if (n < 0)
	{
		printf("'%s'小于'%s'.\n", buffer1, buffer2);
	}
	else
	{
		printf("'%s'和'%s'一样.\n", buffer1, buffer2);
	}

	return 0;
}

//结构体   用户自定义的复合数据类型
//例如描述一个学生
struct Stu//Stu叫做结构体的名称标签
{
	char name[20];//名字
	int age;//年龄
	char sex[50];//性别
	char id[20];//学号
};
int main7()
{
	struct Stu stu = { "xrs",100,"woman","1234567890" };
	
	//结构体的访问和定义
	printf("%s\n", stu.name);
	printf("%d\n", stu.age);
	printf("%s\n", stu.sex);
	printf("%s\n", stu.id);

    //在c99新标下可以随意更改顺序 但是需要在前面加上对应的
	//例如 .name=xrs
	return 0;
}
//在定义结构体时 在结构体内部是不能使用这个类型
//不知道类型多大   导致矛盾
//加上指针 自引用可以成立

//下面是正确的自引用的方式
typedef struct Node
{
	int data;
	struct Node* next;
}STU;
//也是起别名  此时STU  =   struct Node
//多用于链表
int main8()
{
	struct Node n1 = { 10, NULL };
	struct Node n2 = { 20, NULL };

	n1.next = &n2;
	//访问或者可以去修改n2
}
typedef unsigned long long UCL;
//理解为起别名  两者是一样的意思



