#pragma once
//定义联系人数据结构
//姓名
//性别
//年龄
//电话
//地址
#define NAME_MAX 20
#define GENDER_MAX 10      //male female
#define TEL_MAX 20
#define ADDR_MAX 100

typedef struct personInfo
{
	char name[NAME_MAX];
	char gender[GENDER_MAX];
	int age;
	char tel[TEL_MAX];
	char addr[ADDR_MAX];

	
}peoInfo;

//通讯录相关的方法

//初始化
void ContactInit(SL* s1);
//销毁
//添加
//删除