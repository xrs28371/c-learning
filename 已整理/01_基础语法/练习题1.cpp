#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main()
{
    char name[20] = { 0 };   // 初始化
    int age = 0;
    double height = 0;
    char sex = 0;

    printf("请输入姓名、年龄、身高、性别（空格分隔）：\n");
    scanf("%s%d%lf %c", name, &age, &height, &sex);
    //         ↑不加&  ↑%lf  ↑%c前有空格

    printf("\n===== 学生信息 =====\n");
    printf("姓名：%s\n", name);
    printf("年龄：%d岁\n", age);
    printf("身高：%.2f米\n", height);
    printf("性别：%c\n", sex);
    printf("===================\n");

    return 0;
}