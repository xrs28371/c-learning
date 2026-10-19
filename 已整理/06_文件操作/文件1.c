#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include<ctype.h>
#include<string.h>
#include<assert.h>
#include<stdlib.h>
#include<limits.h>
int main()
{
	//文件指针
	FILE* fp=fopen("E:\\教学课\\code\\1.txt","r");
	//r代表只读
	//w代表只写
	//a代表追加
	if (fp == NULL)
	{
		printf("文件打开失败");
		return 1;
	}
	printf("文件打开成功");
	
	fclose(fp);
	//打开就意味要去关闭
	fp = NULL;
	return 0;
}