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

