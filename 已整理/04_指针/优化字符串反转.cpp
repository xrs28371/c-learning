#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
/*
题目 2：字符串反转（原地）
void reverse_str(char* s);
- 把字符串原地反转，"hello" → "olleh"
- 测试：char s[] = "hello"; reverse_str(s); printf("%s", s); → olleh
- 知识点：字符串遍历、'\0'、首尾交换直到中间（和数组反转一个套路，但要注意找结尾用的是 '\0'）
*/
void reverse_str(char* arr)
{
	char* p1 = &arr[0];
	char* p2 = arr;
	
	while (*p2 != '\0')//找到p2什么时候停下
	{
		p2++;
	}
	p2--;//退回最后一个字符
	
	while (p1 < p2)
	{
		int tmp = *p1;
		*p1 = *p2;
		*p2 = tmp;
		p1++;
		p2--;
	}


}
int main()
{
	char arr[] = "hello";
	reverse_str(arr);
	for (int i = 0;i < 5;i++)
	{
		printf("%c ", arr[i]);
	}
	return 0;
}