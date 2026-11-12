#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include "library.h"

/* TODO：自己实现应用层功能，菜单选择后必须实际调用到这里的函数。 */
/* 这里不提供输入处理、业务判断或查找循环的实现。 */

/*
  1. 定义一个临时的 Equipment 变量，接收一条器材的完整信息。
  2. 输入编号、名称、分类、总数量；已借出数量直接设为 0。
  3. 检查输入是否成功、编号是否重复、数量是否合法。
  4. 输入插入位置，检查是否在 0～size。
  5. 全部检查通过，再调用 BInsert。
  */
int x = 0;
Equipment tmp = { 0 };

void EquipmentAdd(B* ps)
{
	Equipment tmp = { 0 };
	printf("请输入编号");
	if (scanf("%d", &tmp.id) != 1)
	{
		printf("编号输入失败\n");
		return;
	}
	printf("请输入名称");
	scanf("%39s", &tmp.name);
	printf("请输入分类");
	scanf("%19s", &tmp.category);
	printf("请输入总数量");
	if (scanf("%d", &tmp.total) != 1)
	{
		printf("总数量输入失败\n");
		return;
	}
	printf("请输入总数量");
	if (scanf("%d", &tmp.borrowed) != 1)
	{
		printf("总借出输入失败\n");
		return;
	}
	int x = 0;
	printf("请输入插入位置");
	scanf("%d", &x);
	if (x<0 && x>ps->size)
	{
		printf("无效位置");
		return;
	}
	BInsert(ps, x, tmp);



}



//删除：按编号删除。不存在时提示；仍有器材借出时拒绝删除。
void EquipmentDelete(B* ps,int x) 
{
	printf("请输入删除的编号");
	scanf("%d", &x);
	if (x<0 && x>ps->size)
	{
		printf("输入错误");
		return;
	}
	int pos=EquipmentFind(ps, x);
	if (pos == -1)
	{
		printf("无法删除");
		return;
	}
	BErase(pos, x);

}


//修改：按编号修改名称、分类和总数量。编号保持不变。
//新总数量不能小于当前已借出数量；失败不能破坏原记录。
void EqiupmentRevise(B* ps, int x)
{
	printf("请输入编号");
	scanf("%d", &x);
	if (x<0 && x>ps->size)
	{
		printf("输入错误");
		return;
	}
	
	

}


//4. 查找：按编号查找。找到只显示匹配的一条，不存在要有明确提示。
//业务函数可共用一个查找接口：返回匹配下标，不存在返回 - 1。

int EquipmentFind(B* ps, int id)
{
	for (int i = 0;i < ps->size;i++)
	{
		if (ps->arr[i].id == id)
		{
			return i;
		}
		
	}
	return -1;
}


//5. 展示：按当前顺序显示全部器材，包含可借数量；空表要有提示。
void EqiupmentShow(B* ps)
{
	if (ps->size == 0)
	{
		printf("此时为空");
		return;
	}
	for (int i = 0;i < ps->size;i++)
	{
		printf("编号：%d 名称：%s 分类：%s 总数量：%d 已借出：%d\n",
			ps->arr[i].id,
			ps->arr[i].name,
			ps->arr[i].category,
			ps->arr[i].total,
			ps->arr[i].borrowed);
	}
}

//6. 借出：输入编号与借出数量。数量必须是正整数且不能超过可借数量。
void EqiupmentBorrowed(B* ps, int id, int x)
{
	printf("请输入编号");
	scanf("%d", &id);
	int pos=EquipmentFind(ps, id);
	if (pos == -1)
	{
		printf("输入的编号不存在");
		return;
	}
	printf("请输入借出的数量");
	scanf("%d", &x);
	if (x < 0)
	{
		printf("输入错误");
		return ;
	}
	ps->arr[pos].borrowed += x;
	printf("此时借出的数量为%d", ps->arr[pos].borrowed);

}


//7. 归还：输入编号与归还数量。数量必须是正整数且不能超过已借出数量。
void EquipmentReturn(B* ps, int id, int x)
{
	printf("请输入编号");
	scanf("%d", &id);
	int pos = EquipmentFind(ps, id);
	if (pos == -1)
	{
		printf("输入的编号不存在");
		return;
	}
	printf("请输入归还的数量");
	scanf("%d", &x);
	if (x < 0&&x>ps->arr[pos].borrowed)
	{
		printf("输入错误");
		return ;
	}
	ps->arr[pos].borrowed -= x;
	printf("已经归还%d本", x);
}


//8. 统计：显示器材种类数、器材总件数、已借出总件数、可借总件数。
void EquipmentAll(B* ps)
{

}
