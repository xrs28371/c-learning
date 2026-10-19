#define  _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
//数组名代表了数组首元素的地址
int main1()
{
	int arr[10] = { 1,2,3,4,5,6,7,8,9,10 };
	int* p1 = &arr[0];
	int* p2 = arr;
	int(* p3)[10] = &arr;
	//主要用作于二维数组
	//前面看作为指针，后面代表了指向了一个长度为10的数组
	//放的时int类型的数组  并且里面都是整型的元素



	//指向二维数组时
	int arr2[3][4];
	int(*p4)[4] = arr2;//指向每一列的数组
	
	
	printf("&arr[0]+1=%p\n", &arr[0] + 1);
	printf("&arr[0]=%p\n", &arr[0] );

	printf("arr=%p\n", arr);
	printf("arr+1=%p\n", arr+1);
	//此时前两个都是代表了数组首元素的地址和下一个元素的地址
	//int 类型代表四个字节 所以下一位地址加四

	//这里加了四十个字节 说明加到了数组最后之后的地址
	printf("&arr=%p\n", &arr );//整个数组的地址
	printf("&arr+1=%p\n", &arr+1 );
	return 0;
}


void printf_arr(int* p, int len)
{
	int arr[4] = { 1,2,3,4 };
	for (int i = 0;i < len; i++)
	{
		printf("%d ", *(p + i));
		//等价于printf("%d ",p[i])
		//[]自带了解引用
	}
	printf("\n");
}
int main2()
{
	int arr[4] = { 1,2,3,4 };
	int len = sizeof(arr) / sizeof(arr[0]);
	printf_arr(arr, len);
	return 0;
}


//二级指针
int main()
{
	int a = 10;
	int* p1 = &a;
	int** p2 = &p1;
	printf("%d\n", *p1);
	printf("%d\n", **p2);
	
	
	//此时两个都打印了p1的地址
	printf("%p\n", p2);
	printf("%p\n", &p1);
	

}