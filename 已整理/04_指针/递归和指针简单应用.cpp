#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
//定义一个包含 10 个整数的数组，使用 sizeof 计算数组长度
/*使用指针遍历并输出所有元素；
计算所有元素的和；
输出数组中的最大值；
输出数组的逆序内容。  倒着打印
*/

int main()
{
	
	
	int arr[10] = { 1,2,3,4,5,6,7,8,9,10 };
	int len = sizeof(arr) / sizeof(arr[0]);
	int* p = &arr[0];
	for (int i = 0;i < len;i++)
	{
		printf("%d ", *(p + i));
	}
	
	
	int sum = 0;
	for (int i = 0;i < len;i++)
	{
		sum += *(p + i);
		
	}
	printf("%d\n", sum);
	
	//假设第一个数字最大
	int max = *p;
	for (int i = 1;i < len;i++)
	{
		if (*(p + 1) > max)
		{
			max = *(p + 1);
		}
	}
	printf("%d\n", max);

	for (int i = len - 1;i >=0;i--)
	{
		printf("%d ", *(p + i));
	}
return 0;
}