#define  _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
/*题目 4：字符串拼接（实现自己的 strcat）
void my_strcat(char* dest, const char* src);
- 把 src 的字符串拼到 dest 的末尾（含结尾的 '\0'）
- 约定：dest 的空间足够大（由调用方保证，如 char dest[20] = "hello";）
-  测试：dest="hello" + src="world" → dest 变为 "helloworld"；src 为空串 → dest 不变
*/
void my_strcat(char* dest, const char* src)
{
	char* d = dest;
	while (*d != '\0')
	{
		d++;
	}
	const char* s = src;
	while (*s!='\0')
	{
		*d++ = *s++;
	}

}