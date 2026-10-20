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
int main4()
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
//fgets
//char *fgets(char*str,int num,FILE*stream)
//从stream指定输入流中读取字符串，直到读取到换行符，文件木哦为或达到指定字符数
//str：是指向字符数组的指针，str指向的空间用于存储读取到的字符串
//num：最大读取字符数  ，实际最多读取num-1个字符
//stream：输入流的文件指针
int main5()
{
	FILE* pf = fopen("E:\\教学课\\code\\1.txt", "r");
	assert(pf != NULL);
	char arr1[100];
	char* ret = fgets(arr1, sizeof(arr1), pf);
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
//feof  ferror
//int feof(FLIE*str)
//检测str指针指向的流是否遇到文件末尾
//int ferror(FLIE* str)
//检测str指针指向的流是否发生读/写错误
int main6()
{
	FILE* pf = fopen("E:\\教学课\\code\\1.txt", "r");
	assert(pf != NULL);

	for (int i = 0; i < 12; i++)
	{
		int c = fgetc(pf);
		if (c == EOF) // 如果读取到 EOF
		{
			if (feof(pf))
			{
				printf("\n遇到文件末尾\n");
				break; // 读到文件末尾通常直接跳出循环
			}
			else if (ferror(pf))
			{
				printf("\n读取发生了错误\n");
				break;
			}
		}
		else
		{
			// 正常读取到的字符在这里打印
			fputc(c, stdout); // 或者使用 putchar(c);
		}
	}

	fclose(pf);
	pf = NULL;
	return 0;
}
//如果想看到ferror
//示例如下
//将 r 只读 变成 w修改 
//当你想去读取 但是我编译修改 此时就会出现ferror的错误
int main7()
{
	FILE* pf = fopen("E:\\教学课\\code\\1.txt", "w");
	assert(pf != NULL);

	for (int i = 0; i < 12; i++)
	{
		int c = fgetc(pf);
		if (c == EOF) // 如果读取到 EOF
		{
			if (feof(pf))
			{
				printf("\n遇到文件末尾\n");
				break; // 读到文件末尾通常直接跳出循环
			}
			else if (ferror(pf))
			{
				printf("\n读取发生了错误\n");
				break;
			}
		}
		else
		{
			// 正常读取到的字符在这里打印
			fputc(c, stdout); // 或者使用 putchar(c);
		}
	}

	fclose(pf);
	pf = NULL;
	return 0;
}
//fprintf
//int fprintf(FLIE*str,const char*for,...)
//str:指向FLIE对象的指针，表示要写入的文件流
//for：格式化字符串，包含要写入的文本和格式说明符
//...:可变参数列表，提供与格式字符串中说明符对应的数据

//返回值
// 成功，返回写入的字符总数
//失败，先设置对应流的错误指示器，再返回负值，通过ferror检测

//示例
typedef struct Stu
{
	char name[30];
	int age;
	float score;
}STU;
int main8()
{
	STU s = { "zhangsan" ,10,19.9f};
	FILE* pf = fopen("E:\\教学课\\code\\1.txt", "w");
	assert(pf != NULL);
	fprintf(pf,"% s % d % .1f" , s.name, s.age, s.score);
	fclose(pf);
	pf = NULL;
	
	return 0;
}

//fscanf
//int fscanf(FLIE* str ,const char *format,...)
//从指定文件流读取格式化数据的函数
//str:指向FLIE对象的指针，表示读取的文件流
//format：格式化字符串，定义如何解析输入数据
//...:可变参数列表。提供存储数据的变量地址
int main9()
{
	STU s ;
	FILE* pf = fopen("E:\\教学课\\code\\1.txt", "r");
	assert(pf != NULL);
	fscanf(pf, "%s %d %f", s.name, &(s.age), &(s.score));
	fprintf(stdout, "%s %d %.1f", s.name, s.age, s.score);
	fclose(pf);
	pf = NULL;
	return 0;
}
//fread fwrite 一般用于二进制
// rb 读二进制  wb 写二进制
//size_t fwrite(const void*ptr,size_t size,size_t count,FLIE*str)
// ptr 表示 要写入的数据
//size 表示 数据的类型的大小
// count 表示 输入数据的数量
//str 表示 写入的目标文件
int main10()
{
	FILE* pf = fopen("E:\\教学课\\code\\1.bin", "wb");//此时是二进制输入
	assert(pf != NULL);
	int data[] = { 1,2,3,4,5 };
	size_t count = fwrite(data, sizeof(int), 5, pf);
	printf("%zu\n", count);
	fclose(pf);
	pf = NULL;
	return 0;
}
//fread
/*
size_t fread(
	  void *ptr,     // 数据存到哪里
	  size_t size,   // 每个数据项占几个字节
	  size_t count,  // 最多读几个数据项
	  FILE *stream   // 从哪个文件读取
 );*/
int main11()
{
	FILE* pf = fopen("E:\\教学课\\code\\1.bin", "rb");//此时是二进制输入
	assert(pf != NULL);
	int data[5];
	size_t num_read = fread(data, sizeof(int), 5, pf);
	if (num_read != 5)
	{
		//万一只有两个
		if (foef(pf))
		{
			printf("Reached end file\n");

		}
		else if (ferror(pf))
		{
			printf("Error end file");
		}
		else
		{
			for (int i = 0;i < 5;i++)
			{
				printf("%d ", data[i]);
			}
		}
	}
	fclose(pf);
	pf = NULL;
	return 0;
}


//文件的随机读写
//用 fseek 移动、ftell 查询、rewind 回开头
//fseek 根据文件
//int fseek (FLIE*stream, long int offset,int origin);
//stream(文件指针）：你要操作的那个文件
//offset（偏移量）：你要移动多少字节
// 正数：向后移动
// 负数：向前移动（文件开头）
//0：不移动
//origin（起始位置）：从哪里开始算偏移量
// 0 文件开头
// 1 当前光标位置
// 2 文件末尾
int main12()
{
	FILE* pf = fopen("E:\\教学课\\code\\1.txt", "w");//此时是二进制输入
	assert(pf != NULL);
	fputs("abedefghi", pf);

	fseek(pf, -2, 1);
	char str[10];
	fgets(str, 2, pf);
	printf("%s ", str);


	fclose(pf);
	pf = NULL;
	return 0;
}

//ftell
//返回文件指针相对于起始位置的偏移量
//long int ftell(FLIE* stream);
int main13()
{
	FILE* pf = fopen("E:\\教学课\\code\\1.txt", "w");//此时是二进制输入
	assert(pf != NULL);
	fputs("abedefghi", pf);

	long int ret = ftell(pf);
	printf("%ld\n",ret);
	//知道有多少个字符


	fclose(pf);
	pf = NULL;
	return 0;
}
