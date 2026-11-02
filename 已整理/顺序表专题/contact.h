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



//要用到顺序表相关的方法，对通讯录的操作实际时对顺序表进行操作
//给顺序表改名字，叫做通讯录
typedef struct Seqlist Contact;
//通讯录相关的方法

//初始化
void ContactInit(Contact* con);
//销毁
void ContactDesTroy(Contact* con);
//添加
 void ContactAdd(Contact*con);
//删除
 void ContactDel(Contact* con);
 //修改
 void ContactModify(Contact* con);
 //查找
 void ContactFind(Contact* con);
 //展示
 void ContactShow(Contact* con);
