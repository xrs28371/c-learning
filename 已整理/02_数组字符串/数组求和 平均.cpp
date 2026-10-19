#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main()
{
    //第一步定义全部的变量
    int n = 0;
    int arr[20];
    long sum = 0;
   

    //输入n，检查范围
    do
    {
        printf("请输入你的n的值（1<=n<=20):\n");
        scanf("%d", &n);
    }
    while (n < 1 || n > 20);

    //输入n个数据存入数据
    printf("请输入 %d 个数据\n", n);
    for (int i = 0;i < n;i++)
    {
        scanf("%d", &arr[i]);
        sum += arr[i];
    }
    
    //算平均值，类型是强制转换
    double avg = (double)sum / n;

    //输出
    printf("和：%ld\n", sum);
    printf("平均值：%.2f\n", avg);

    return 0;

}