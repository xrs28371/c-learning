/*
题目 1：交换两个变量（传地址）
void swap(int* a, int* b);
- 交换 a、b 指向的两个 int 的值
- 测试：int x = 3, y = 5; swap(&x, &y); → x=5, y=3
- 知识点：传地址修改原值（这是指针最重要的用途，也是很多算法的基础）
*/
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
void swap(int* a, int* b)
{
	int tmp = *a;
	*a = *b;
	*b=tmp;
}
int main()
{
	int x = 3;
	int y = 5;
	printf("交换前：x=%d y=%d \n", x, y);
	int* p1 = &x;
	int* p2 = &y;
	swap(&x, &y);
	printf("交换后：x=%d y=%d \n", x, y);
	return 0;

}