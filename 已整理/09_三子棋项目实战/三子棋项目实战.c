//·负责游戏整体的逻辑实现·负责游戏整体的协作
#include<stdio.h>
#include"game.h"


void menu()
{
	printf("**************************\n");
	printf("******     1.paly   ******\n");
	printf("******     0.exit   ******\n");
	printf("**************************\n");
}
int main()
{
	char board[ROW][COL];
	//定义棋盘

	init_board(board,ROW,COL);
	//初始化一个空棋盘

	print_init_board(board, ROW, COL);
}