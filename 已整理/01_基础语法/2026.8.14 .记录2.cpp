#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main()
{
	//定义只能有一个，字符型就是char类型
	char ch = 'a';//char为数据类型，ch可理解我箱子，把a（数值，一个值）放在变量char这个类型之中，不同类型对应不同的变量
	char ch2 = 'b';//不能同时放很多，但是可以放不同的值
	ch2 = 'c';//c将b覆盖，结果只会展示c
	int f = 10;//输出整型,格式化输出，占位符
	printf("%d\n"f);
	printf("%c\n", ch2);
	ch = '0';//字符0，数值为48
	printf("%c\n", ch);
	return 0;
}/*如果数值为数字，输出结果以ASCLL代码显示，数字不需要单引号
 A-Z对应了65~90
 a~z对应了97~122
 A与a之间差值为32*/

//\n   转义字符，换行，且数值为10
//0到31为不可打印字符
//测试邮箱是否覆盖