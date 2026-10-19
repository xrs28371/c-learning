#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
int main()
{
	double weight = 0;
	char sex = 0;

	printf("请输入你的体重:");
	scanf("%lf", weight);
	int tmp;
	while ((tmp = getchar()) != '\n' && tmp != EOF);
	
	printf("请输入性别M/F：");
	sex = getchar();

	printf("体重：%.2f，性别：%c\n", weight, sex);
	return 0;
}