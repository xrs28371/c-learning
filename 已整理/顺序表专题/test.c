#include"单链表.h"

void SListTesr01()
{
	//链表是由一个一个节点组成
	//创建节点
	SLTNode* node1 = (SLTNode*)malloc(sizeof(SLTNode));
	node1->data = 1;

	SLTNode* node2 = (SLTNode*)malloc(sizeof(SLTNode));
	node2->data = 2;

	SLTNode* node3 = (SLTNode*)malloc(sizeof(SLTNode));
	node3->data = 3;

	SLTNode* node4 = (SLTNode*)malloc(sizeof(SLTNode));
	node4->data = 4;

	//将4个节点连接

	node1->next = node2;
	node2->next = node3;
	node3->next = node4;
	node4->next = NULL;

	//调用打印
	SLTNode* plist = node1;//指向第一个节点
	SLTPrint(plist);
}

int main()
{
	SListTesr01();
	return 0;
}