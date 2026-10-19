#define  _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
//指针交换
void swap(int*px,int*py)
{
	int twp = *px;
	*px = *py;
	*py = twp;
}
int main()
{
	int a = 10;
	int b = 20;
	printf(" a==%d  b==%d\n", a, b);
	swap(&a, &b);
	printf("a===%d   b===%d\n", a, b);
		return 0;

}