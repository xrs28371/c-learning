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
