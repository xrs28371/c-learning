#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
int main()
{
		int score = 0;
		printf("请输入成绩");
		scanf("%d", &score);//&取地址，定义score
		printf("成绩是：%d\n", score);

		int b = 0;
		int ret = scanf("%d%d", &score, &b);//在scanf里面有什么就要加什么
		printf("%d,%d\n",score,b);
		printf("ret = %d\n", ret);

		//scanf是函数
		//函数是一个功能
		//main函数 printf函数
		//返回值
		//scanf返回值是一个整数。表示成功读取的变量个数
		//Eof 文件结束标识
		int a = 0;
		int c = 0;
		float f = 0.0f;
		int r = scanf("%d %d %f", &a, &c, &f);
		printf("a=%d,c=%d,f=%f\n",a,c,f);
		printf("r=%d\n", r);

		//如果只读取两个，三次ctrl+z，中断读取
		//规定一个读取不成功，默认返回-1

		//字符串的存储方式
		//char name[]="xrsxrs"，数组，中括号及为数组
		//字符串默认以\0结尾，标志当前的字符串已经结束


		char name[6];//大小是六，注意理论最多输入五个，有一个位置给/0留的
		scanf("%s", name);//不需要取地址，后续讲到指针
		printf("%s\n", name);

		//循环输入
	int count = 1;
	while (count <= 10000000000)//检测条件是否满足
	{
		printf("蛋可爱\n");
		count = count + 1;
	}
	
	int y;
	int x;
	while (scanf("%d %d", &y, &x) != -1)
	{
		printf("y=%d,x=%d\n", y, x);


	}

	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	return 0;
}