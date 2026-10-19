#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main()
{
    int arr[10000];
    int n;

    printf("请输入 n：");
    scanf("%d", &n);

    printf("请输入 %d 个整数：", n);
    for (int i = 0; i < n; i++)
        scanf("%d", &arr[i]);

    // 逆序存放：首尾对调，只换一半
    for (int i = 0; i < n / 2; i++)
    {
        int tmp = arr[i];
        arr[i] = arr[n - 1 - i];
        arr[n - 1 - i] = tmp;
    }

    // 只输出这一次！
    for (int i = 0; i < n; i++)
        printf("%d ", arr[i]);

    return 0;
}