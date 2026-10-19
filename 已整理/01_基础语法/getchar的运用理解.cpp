#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
int main()
{
	char ch = getchar();
	printf("%c\n", ch);
	return 0;
	//getchar的意义
	//清理缓存区残留回车
	//解决scanf后读字符的bug
	//获取单个字符
	//程序暂替，等待用户确认
	//当后面要用%c，getchar（），gets（）读取字符的时候需要清理，不然逻辑崩溃
	//当后面继续使用%d，%s等时候不需要
	//while(getchar() != '\n');
	//如上清理所有多余缓存，以防卡顿
}
//while(getchar()!='\n');
//用于清理缓存