
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>//一维数组

int main()
{
	//里面出现随机值
	int arr1[5];//编号是从0开始，0，1，2，3，4，这里没有进行初始化
	
	int arr2[5] = { 1,2,3,4,5 };//定义数组的同时进行初始化
	
	int arr3[] = { 1,2,3,4,5,6,7 };//根据后面赋值数的个数，来确定数组的大小

	int arr4[5] = { 1,2,3 };//大小是5，只不过放了3个数据，剩下两个会默认是0

	printf("%d\n", arr2[1]);
	printf("%d\n", arr4[3]);//下标不存在负数，0到n-1

	
	return 0;
}