#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include<ctype.h>
#include<string.h>
#include<assert.h>
#include<stdlib.h>
#include<limits.h>

//结构体传参
struct S
{
	int data[1000];
	int num;
};
void print1(struct S s)
{
	printf("%d\n", s.num);
}
int main1()
{
	struct S s = { {1,2,3},1000 };
	print1(s);
	struct S* ps = &s;
	printf("%d\n", (*ps).num);
	printf("%d\n", ps->num);//此时是用指针的访问
	return 0;
}
//很明显此时如果传值需要复制四千多字节的地址
//此时利用传地址更加迅速



//  联合体  又叫  共同体
// 是由一个或者多个成员构成     
// 特点是所有成员都共用同一块内存空间
//并且只为最大的成员分配足够的内存空间 

union UN
{
	char s;
	int a;
};
//同时遵守内存对齐
//当最大成员不是对齐数的整数倍时，需要补到整数倍
union Un
{
	char a[5];
	int b;
};
int main2()
{
	union UN s = { 11 };//通常只存储一个有效值
	union Un sa = { 11 };
	printf("%zu\n", sizeof(s));
	printf("%zu\n", sizeof(sa));
	printf("%d\n",  s.a);
	return 0;
}
//联合体的应用最多来判断大小端机器
int check_sys()
{
	union
	{
		int i;
		char c;
	} un;

	un.i = 1;
	return un.c;
}

int main3()
{
	int ret = check_sys();
	if (ret == 1)
		printf("当前系统：小端模式\n");
	else
		printf("当前系统：大端模式\n");

	return 0;
}
//联合体的其他使用场景






//枚举类型
//有限集合的内容都可以使用枚举进行表示    列如 一周几天
//部分不是有限集合不可以使用枚举        列如 整数有多少
enum Day  //星期      枚举类型
{
	Mon=1,//枚举常量   第一个默认为0   但是可以手动赋值
	Tues,
	Wed,
	Thur,
	Fri,
	Sat,
	Sun,
};
//因为在枚举里面所以具有的枚举的性质
//提高了可读性
enum Color
{
	RED1 = 2,
	GREEN2=4,
	BLUE=8,
};
int main4()
{
	enum Color clr = GREEN2;
	printf("%d\n", GREEN2);
	printf("%d\n", Mon);
	printf("%d\n", Tues);
	return 0;
}

//模拟交通灯的转换
enum Trafficlight
{
	RED,
	GREEN,
	YELLOW,
};
int main5()
{
	enum Trafficlight light = RED;
	for (int i = 0;i < 3;i++)
	{
		switch (light)
		{
		   case RED:
		   {
			   printf("红灯停\n");
			   
			   light = GREEN;
			   break;
		   }
		   case GREEN:
		   {
			   printf("绿灯行\n");
			  
			   light = YELLOW;
			   break;
		   }
		   case YELLOW:
			   printf("黄灯减速\n");
			   break;
			

		}
	}
	return 0;
}
//动态内存管理
int main6()
{
	//堆上开辟   里面的值是随机的
	int* p = (int*)malloc(5 * sizeof(int));
	assert(p != NULL);
	if (p == NULL)
	{
		printf("开辟失败\n");
	}
	else
		printf("开辟成功\n");

	for (int i = 0;i < 5;i++)
	{
		*(p + i) = i;
	}
	for (int i = 0;i < 5;i++)
	{
		printf("%d ", *(p + i));
	}
	printf("\n");

	//手动释放内存
	//如果开辟内存后不释放
	//会导致堆堆积 
	free(p);
	p = NULL;
	return 0;

}

//与malloc相同的还有两个函数
//calloc 
int main7()
{
	int* p = (int*)calloc(5 , sizeof(int));
	//calloc  默认值为0
	//malloc  默认值为随机
	assert(p != NULL);
	if (p == NULL)
	{
		printf("开辟失败\n");
	}
	else
		printf("开辟成功\n");

	for (int i = 0;i < 5;i++)
	{
		*(p + i) = i;
	}
	for (int i = 0;i < 5;i++)
	{
		printf("%d ", *(p + i));
	}
	printf("\n");

	//手动释放内存
	//如果开辟内存后不释放
	//会导致堆堆积 
	free(p);
	p = NULL;
	return 0;

}
//realloc
//合理调整动态内存的大小
//void*realloc(void*p,size_t size)
// p 是地址   size 是更新后的大小

//realloc  的使用例子
int main8()
{
	int* p = (int*)calloc(5, sizeof(int));
	//calloc  默认值为0
	//malloc  默认值为随机
	assert(p != NULL);
	if (p == NULL)
	{
		printf("开辟失败\n");
	}
	else
		printf("开辟成功\n");

	for (int i = 0;i < 5;i++)
	{
		*(p + i) = i;
	}
	for (int i = 0;i < 5;i++)
	{
		printf("%d ", *(p + i));
	}
	printf("\n");

	//开始扩容
	int *ptr=realloc(p, 10 * sizeof(int));
	//为什么要重新定义一个指针呢
	//因为扩容不一定成功
	//失败了 p指针为空
	//丢失原来的数据
	assert(ptr != NULL);
	if (ptr == NULL)
	{
		printf("开辟内存失败");
		return 1;
	}
	p = ptr;
	for (int i = 0;i < 10;i++)
	{
		printf("%d ", *(p + i));
	}

	//此时此刻你扩容的打印就是随机值

	//此时需要再次赋值显示的才不会是随机值
	for (int i = 0;i < 10;i++)
	{
		*(p + i) = i;
	}
	//再次打印
	for (int i = 0;i < 10;i++)
	{
		printf("%d ", *(p + i));
	}

	free(p);
	p = NULL;
	return 0;
}

//常见的动态内存的错误
//第一点
//对于NULL指针的解引用行为
void test()
{
	int* p = (int*)malloc(INT_MAX * 4);
	
	*p = 20;
	free(p);
	p = NULL;
}
int main9()
{
	 test();
	return 0;
}

//对动态空间的越界访问
void test1()
{
	int i = 0;
	int* p = (int*)malloc(10 * sizeof(int));
	if (NULL == p)
	{
		exit(1);
	}
	for (int i = 0;i <= 10;i++)
	{
		*(p + i) = i;
	}
	free(p);
	p = NULL;
}
int main10()
{
	test1();
	return 0;
}


//对同一块动态内存多次释放
void test2()
{
	int* p = (int*)malloc(100);
	free(p);
	free(p);
	//此时就对于p进行多次释放
	p = NULL;
}

//忘记释放也会导致内存泄露
//free（）是必不可少的


//列题1
void GetMemory1(char* p)
{
	p = (char*)malloc(100);
}
void Test1(void)
{
	char* str = NULL;
	GetMemory1(str);
	strcpy(str, "hello world");
	printf(str);
}
int main11()
{
	Test1();
	return 0;
}

//只修改了形参的指向没有修改实参的指向

//我们该做如下修改
int GetMemory(char** pp)
{
	*pp = malloc(100);

	if (*pp == NULL)
	{
		return 0;
	}

	return 1;
}

void Test(void)
{
	char* str = NULL;
	GetMemory(&str);
    strcpy(str, "hello world");
	printf("%s\n", str);

	free(str);
	str = NULL;
}

int main(void)
{
	Test();
	return 0;
}
//改变实参只能传地址


