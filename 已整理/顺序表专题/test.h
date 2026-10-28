#pragma once
#define N 100
#include<stdio.h>
#include<stdlib.h>
#include<assert.h>
//静态顺序表的定义
struct SeqList
{
	int arr[N];//定长的数组
	int size;//顺序表当前有效的数据个数
};


typedef int SLDataType;

//动态顺序表
struct Seqlist
{
	 SLDataType * arr;
	int size;//有效数据个数
	int capacity;//空间大小
};

typedef struct Seqlist SL;

//初始化
void SLInit(SL * ps);
//顺序表的销毁
void SLDestory(SL* ps);

//头部插入删除/ 尾部插入删除
void SLPushBack(SL* ps, SLDataType x);//顺序表 数据类型
void SLPushFront(SL* ps, SLDataType x);

void SLPopBack(SL* ps);
void SLPopFront(SL* ps);




