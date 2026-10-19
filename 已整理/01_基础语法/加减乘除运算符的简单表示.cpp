#define  _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
//算术操作符
//+ - * /
//如下演示加法，其他类似
int main()
{
	int a = 0;
	int b = 0;
	while(scanf("%d %d", &a, &b)!=EOF)//当运用while循环不能加；
	{
		int x = a + b;
		printf("%d\n", x);
		}
	return 0;
}
//int y=3/2    输出为1 除号左右都是整数只能以整数形式输出
//用float也是1.000000  不会为1.5


//若要显示小数
//以 float x=3.0/2   这样就能输出1，5
//至少有一个浮点数

