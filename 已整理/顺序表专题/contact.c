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
		if (0==strcmp(con->arr[i].name,name))
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
	//表头：姓名 性别 年龄电话地址
	printf("%s %s %s %s %s\n", "姓名", "性别", "年龄", "电话", "地址");
	//遍历通讯录
	for (int i = 0;i < con->size;i++)
	{
		printf("%3s %3s %3d %3s %3s\n",//手动调整格式
			con->arr[i].name,
			con->arr[i].gender,
			con->arr[i].age,
			con->arr[i].tel,
			con->arr[i].addr);
	}
}
//修改
void ContactModify(Contact* con)
{
	//要修改的联系人数据存在
	char name[NAME_MAX];
	printf("请输入要修改的用户姓名：\n");
	scanf("%s", name);
	int find = FindByName(con, name);
	if (find < 0)
	{
		printf("要修改的联系人数据不存在！\n");
		return;
	}

	//直接修改
	printf("请输入新的姓名：\n");
	scanf("%s", con->arr[find].name);

	printf("请输入新的性别：\n");
	scanf("%s", con->arr[find].gender);

	printf("请输入新的年龄：\n");
	scanf("%s", con->arr[find].age);

	printf("请输入新的电话：\n");
	scanf("%s", con->arr[find].tel);

	printf("请输入新的地址：\n");
	scanf("%s", con->arr[find].addr);

	printf("修改成功！\n");

}

//查找
void ContactFind(Contact* con)
{
	char name[NAME_MAX];
	printf("请输入你要查找的联系人姓名\n");
	scanf("%s", name);
	int find = FindByName(con, name);
	if (find < 0)
	{
		printf("要修改的联系人数据不存在！\n");
		return;
	}
	printf("%s %s %s %s %s\n", "姓名", "性别", "年龄", "电话", "地址");
	//遍历通讯录
	for (int i = 0;i < con->size;i++)
	{
		printf("%3s %3s %3d %3s %3s\n",//手动调整格式
			con->arr[find].name,
			con->arr[find].gender,
			con->arr[find].age,
			con->arr[find].tel,
			con->arr[find].addr);
	}

}