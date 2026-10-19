#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include<ctype.h>
#include<string.h>
#include<assert.h>
int main1()
{
	const char* str1 = "abedrd";
	const char* str2 = "nnn";
	// 3     6
	//无符号的整型 结果应该也是无符号的  
	if (strlen(str2) - strlen(str1) > 0)
	{
		printf("str2>str1\n");
	}
	else
	{
		printf("str1>str2\n");
	}
	return 0;
	// 结果输出会是第一个结果 strlen返回的数据是无符号的整形 

}
int my_strlen(const char* p)
{
	int count = 0;
	assert(p);//括号里面写绝对成立的东西  这里是防止p为空指针
	//等价于
	//assert(p!=NULL)
	while (*p)
		//等价于while(*p!='\0')
	{
		count++;
		p++;
	}
	return count;

} 
//strcpy  
//字符串拷贝  ，拷贝到源头字符串的\0为止
//char* strcpy(char * destination, const char * source );
// destination:指针，指向目的地空间
//  source:指针，指向源头数据
char* my_strcpy(char* dest, const char* src)
{
	assert(dest != NULL && src != NULL);
	char* ret = dest;
	while (*src!='\0')
	{
		*dest = *src;
		dest++;
		src++;
	}
	*dest = '\0';
	return ret;
}
int main2()
{
	char str_dst[10] = { 0 };
	char* src = "abcd";
	char* ret = my_strcpy(str_dst, src);
	//将abcd拷贝到数组里面
	//有返回值可以有更多用法
	printf("ret=%s\n", ret);

}
//strcat
//字符串追加 把source指向的源字符串中所有字符都追加到dest指向的空间中
 
int main()
{
	char str_src[20] = "hello";
	char* str_dest = "world";
	char* ret = strcat(str_src, str_dest);
	return 0;
}

//实现自己的strcat
char* my_strcat(char* dest,const char* src)
{
	assert(dest != NULL && src != NULL);
	//先走到\0
	char* ret = dest;
	while (*dest != '\0')
	{
		dest++;
	}
	//开始拼接
	while (*src != '\0')
	{
		*dest = *src;
		dest++;
		src++;
	}
	*dest = '\0';
	return ret;
}