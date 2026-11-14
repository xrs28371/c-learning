#include<stdio.h>




//双指针法 
int removeElement(int* nums, int numsSzie, int val)
//     数组长度
{
	//创建变量
	int src, dst;
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