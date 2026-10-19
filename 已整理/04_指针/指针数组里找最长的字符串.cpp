#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include<string.h>
/*
const char* longest(const char* words[], int n);
- words 是指针数组（每个元素指向一个字符串），返回最长的那个字符串的指针
- 测试：const char* words[] = {"cat", "elephant", "dog", "hi"}; 
→ 返回指向 "elephant" 的指针，printf("%s", p) 输出 elephant*/
const char* longest(const char* words[], int n)
{
	if (words == NULL || n <= 0)
	{
		return NULL;
	}

	const char* longest_word = words[0];
	size_t longest_length = strlen(words[0]);
	for (int i = 0;i < n;i++)
	{
		size_t current_length = strlen(words[i]);
		if (current_length > longest_length)
		{
			longest_length = current_length;
			longest_word = words[i];
		}
	}
	return longest_word;

}
int main()
{
	const char* words[] = { "cat", "elephant", "dog", "hi" };
	int n = sizeof(words) / sizeof(words[0]);
	const char*p= longest(words,n);
	printf("%s ", p);
	return 0;

}