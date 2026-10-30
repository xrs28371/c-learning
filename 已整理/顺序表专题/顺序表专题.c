#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include<ctype.h>
#include<string.h>
#include<assert.h>
#include<stdlib.h>
#include<limits.h>
#include "test.h"
//什么叫做数据结构  
//1.存储数据
//2.存储的数据方便查找

//顺序表底层是数组
//更加便利去插入和删除数据


//顺序表是线性表的一种
//线性表  也是具有相同特性的数据结构的集合
//物理结构：这些数据在内存里怎么存放，以及怎样找到前后相邻的元素
//同时也是不一定连续的
//逻辑结构：在想法中是按照先后顺序来排放的
//是连续的

//顺序表的特性
//物理结构是连续的
//逻辑结构是连续的

void SLTest01()
{
	SL s1;
	SLInit(&s1);
	SLPushBack(&s1, 1);
	SLPushBack(&s1, 2);
	SLPushBack(&s1, 3);
	SLPushBack(&s1, 4);
	SLPushBack(&s1, 5);
	SLPushBack(&s1, 6);
	SLprint(s1);

	SLPushFront(&s1, 1);
	SLPushFront(&s1, 1);
	SLPushFront(&s1, 1);
	SLPushFront(&s1, 1);
	SLPushFront(&s1, 1);
	SLprint(s1);
	//增删查改操作
	//初始化
	
	//使用完销毁
	SLDestory(&s1);
}
int main1()
{
	 SLTest01();
	
	return 0;
}
void SLTest02()
{
	SL s2;
	SLInit(&s2);
	SLPushBack(&s2, 1);
	SLPushBack(&s2, 1);
	SLPushBack(&s2, 1);
	SLPushBack(&s2, 1);
	SLPushBack(&s2, 1);
	SLprint(s2);

	//测试
	SLInsert(&s2, 0, 99);
	SLprint(s2);

	SLInsert(&s2, s2.size, 99);
	SLprint(s2);


	SLErase(&s2, 0);
	SLprint(s2);


	SLDestory(&s2);




	
 }
int main()
{
	SLTest02();
	return 0;
}

