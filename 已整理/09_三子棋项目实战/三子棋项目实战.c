//·负责游戏整体的逻辑实现·负责游戏整体的协作

#include"game.h"


void menu()
{
	printf("**************************\n");
	printf("******     1.paly   ******\n");
	printf("******     0.exit   ******\n");
	printf("**************************\n");
}
void game()
{
	char ret = 0;
	menu();
	char board[ROW][COL];
	//定义棋盘

	init_board(board, ROW, COL);
	//初始化一个空棋盘

	print_board(board, ROW, COL);
	//打印棋盘

	//进入游戏环节
	while (1)
	{
		//玩家移动
		palyer_move(board, ROW, COL);
		//打印棋盘
		print_board(board, ROW, COL);
		//是否赢
		ret = is_win(board, ROW, COL);
		if (ret != 'C')
		{
			break;
		}
		//电脑移动了
		pc_move(board, ROW, COL);
		//打印棋盘
		print_board(board, ROW, COL);
		//是否赢
		ret = is_win(board, ROW, COL);
		if (ret != 'C')
		{
			break;
		}

	}
	if (ret == '#')
	{
		printf("电脑赢了\n");

	}
	else if (ret == '*')
	{
		printf("玩家赢了\n");
	}
	else
	{
		printf("平局\n");
	}
	
}
int main()
{
	srand((unsigned int)time(NULL));
	int input = 0;
	do
	{
		menu();
		printf("请输入你的操作:");
		scanf("%d", &input);
		switch (input)
		{
		case 0:
				printf("游戏结束\n");
				break;
		case 1:
			    game();
				break;
		default:
			    printf("请输入正确操作\n");
				break;
		}

	} while (input);
		return 0;
}