#include"contact.h"
#include"test.h"

//初始化
void ContactInit(Contact* con)
{
	//实际上是进行顺序表的初始化
	//但是顺序表的初始化已经实现
	SLInit(con);
}

//销毁
void ContactDesTroy(Contact* con)
{
	SLDestroy(con);
}
//添加数据
void ContactAdd(Contact* con)
{
	//获取用户输入的内容：姓名+性别+年龄+电话+地址
	peoInfo info;
	printf("请输入要添加的联系人姓名：\n");
	scanf("%s", info.name);

	printf("请输入要添加的联系人性别：\n");
	scanf("%s", info.gender);

	printf("请输入要添加的联系人年龄：\n");
	scanf("%d", &info.age);

	printf("请输入要添加的联系人电话：\n");
	scanf("%s", info.tel);

	printf("请输入要添加的联系人地址：\n");
	scanf("%s", info.addr);

	//往统续录中添加联系人数据
	SLPushBack(con, info);


}
int FindByName(Contact* con, char name[])
{
	for (int i = 0;i < con->size;i++)
	{
		if (0==strcmp(con->arr[i].name))
		{
			//找到了
			return i;
		}
	}
	//没有找到
	return -1;
}
//删除
void ContactDel(Contact* con)
{
	//需要存在才能执行删除操作
	//查找
	char name[NAME_MAX];
	printf("请输入要删除的联系人姓名：\n");
	scanf("%s", name);

	int find = FindByName(con, name);

	if (find < 0)
	{
		printf("不存在\n");
		return;
	}
	//存在
	//删除指定
	SLErase(con, find);
	printf("删除成功！\n");



}
//展示
void ContactShow(Contact* con)
{

}
//修改
void ContactModify(Contact* con)
{

}

//查找
void ContactFind(Contact* con)
{

}