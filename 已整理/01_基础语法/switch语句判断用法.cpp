#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
//switch是一种特殊的if else结构，用来判断条件有多个确定结果的情况，
int main()
{
	int num = 0;
	scanf("%d", &num);
	switch (num)//必须是整型表达式
	{
	case 1:
		printf("1\n");
		break;
	case 2:
		printf("2\n");
		break;
	default:
		printf("输入有误\n");
		break;
	}
	return 0;
}