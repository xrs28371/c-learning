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