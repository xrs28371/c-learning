#include"单链表.h"




//双指针法 
int removeElement(int* nums, int numsSzie, int val)
//     数组长度
{
	//创建变量
	int src = 0;
	int dst = 0;
	while (src < numsSzie)
	{
		if (nums[src] == val)
		{
			src++;
		}
		else
		{
			//赋值，两指针++
			nums[dst] = nums[src];
			dst++;
			src++;
		}
	}
	//此时dst的值干好就是新数组的有效长度
	return dst;
}


//合并两个有序数组
//将数组2依次放入数组1的后面，用排序算法对num1进行排序
//思路二：三个指针 从后往前比大小			
void merge(int* nums1, int m, int* nums2, int n)
{
	int l1 = m - 1;
	int l2 = n - 1;
	int l3 = m + n - 1;


	while (l1 >= 0 && l2 >= 0)//只要有一个条件为假就跳出循环
	{
		if (nums1[l1] < nums2[l2])
		{
			nums1[l3--] = nums2[l2--];


		}
		else {
			nums1[l3--] = nums1[l1--];
		}
	}
	//出循环有两种情况：l1<0或者 l2<0
	//是否存在 l1和l2同时为0

	//只需要处理  l2>=0 代表l2的数据还没有完全放入到num1
	while (l2 >= 0)
	{
		nums1[l3--] = nums2[l2--];
	}
	

}



//顺序表的收尾
/*
1.中间/头部的插入删除，时间复杂度为O(N)
2.增容需要申请新空间，拷贝数据，释放旧空间。会有不小的消耗。
3.增容一般是呈2倍的增长，势必会有一定的空间浪费。例如当前容量为100，满了以后增容到200，我们再继续
插入了5个数据，后面没有数据插入了，那么就浪费了95个数据空间。*/


// 中间/头部插入效率底下，增容降低运行效率，增容造成空间浪费
//  链表的出现解决这些问题


// 链表也是线性表的一种  
// 物理结构非连续 
// 逻辑结构是连续的

// 链表是由一个一个的节点构成

//节点有哪些组成部分
//  数据 和下一个的节点的地址

void SLTPrint(SLTNode* phead)
{
	SLTNode* pcur = phead;
	while (pcur != NULL)
	{
		printf("%d->", pcur->data);
		pcur = pcur->next;
	}
	printf("\n");
}