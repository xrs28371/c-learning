#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include<ctype.h>
#include<string.h>
#include<assert.h>
#include<stdlib.h>
#include<limits.h>
//八个文件读写函数
//第一个 fputc
// int fputc (int cha ,FILE *str)
// cha 被写入的字符
// str 一个FILE类型的指针 指向你的输出流 文件

int main1()
{
	FILE* pf = fopen("E:\\教学课\\code\\1.txt", "w");
	assert(pf != NULL);
	fputc('a', pf);
	fputc('b', pf);
	fputc('c', pf);
	fputc('d', pf);
	fputc('e', pf);
	fputc('f', pf);
	fputc('g', pf);

	fclose(pf);
	pf = NULL;
	return 0;
}
//实现循环写入多个字符的
//同时覆盖你上次写入的内容
int main2()
{
	FILE* pf = fopen("E:\\教学课\\code\\1.txt", "w");
	assert(pf != NULL);
	int ch = 0;
	for (int ch = 'a'; ch <= 'z'; ch++)
	{
		fputc(ch, pf);
	}
	fclose(pf);
	pf = NULL;
	return 0;
}


//第二个 fgetc
//int fputc(FILE*str)
// 从str指向流里面读取一个字符
int main3()
{
	FILE* pf = fopen("E:\\教学课\\code\\1.txt", "r");
	assert(pf != NULL);
	for (int i = 0;i < 10;i++)
	{
		int c = fgetc(pf);
		fputc(c, stdout);//stdout就是电脑屏幕

	}
	fclose(pf);
	pf = NULL;
	return 0;
}
int main4()
{
	FILE* pf = fopen("E:\\教学课\\code\\1.txt", "w");
	assert(pf != NULL);

	fputs("hello\0abc", pf);//也是可以不断写入
	//把字符串写入到指定文件，遇到\0就不写了
	
	fclose(pf);
	pf = NULL;
	return 0;
}
//fgets
//char *fgets(char*str,int num,FILE*stream)
//从stream指定输入流中读取字符串，直到读取到换行符，文件木哦为或达到指定字符数
//str：是指向字符数组的指针，str指向的空间用于存储读取到的字符串
//num：最大读取字符数  ，实际最多读取num-1个字符
//stream：输入流的文件指针
int main()
{
	FILE* pf = fopen("E:\\教学课\\code\\1.txt", "r");
	assert(pf != NULL);
	char arr1[100];
	char*ret=fgets(arr1, sizeof(arr1), pf);
	if (ret != NULL) {
		printf("第1次：[%s]\n", arr1);
		printf("第2次：[%s]\n", ret);
	}
	else {
		puts("fgets 没有读到内容");
	}
	
	fclose(pf);
	pf = NULL;
	return 0;



}