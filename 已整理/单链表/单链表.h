#pragma once
#include<stdio.h>
#include<assert.h>
#include<stdlib.h>

//定义链表的节点的结构
typedef int SLTDataType;

typedef struct SListNode
{
	int data;
	struct SListNode* next;//指向下一个节点的指针
}SLTNode;


void SLTPrint(SLTNode* phead);

//尾插
void SLPPushBack(SLTNode** pphead, SLTDataType x);

//头插
void SLPPushFront(SLTNode** pphead, SLTDataType x);

SLTNode* SLTBuyNode(SLTDataType x);

//尾删
void SLTPopBack(SLTNode** phead);

//头删
void SLTPopFront(SLTNode** phead);