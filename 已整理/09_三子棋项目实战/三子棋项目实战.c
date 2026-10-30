//·负责游戏整体的逻辑实现·负责游戏整体的协作

#include"game.h"
#ifdef _WIN32
#include <windows.h>
#endif


void menu(void)
{
	printf("**************************\n");
	printf("******     1.paly   ******\n");
	printf("******     0.exit   ******\n");
	printf("**************************\n");
}
int game(void)
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
		if (!palyer_move(board, ROW, COL))
			return 0;
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
	else if (ret == 'Q')
	{
		printf("平局\n");
	}
	else
	{
		printf("棋盘状态异常，本局结束。\n");
	}
	return 1;
}
int main(void)
{
#ifdef _WIN32
	UINT old_output_cp = GetConsoleOutputCP();
	UINT old_input_cp = GetConsoleCP();
	SetConsoleOutputCP(CP_UTF8);
	SetConsoleCP(CP_UTF8);
#endif
	srand((unsigned int)time(NULL));
	int input = 0;
	do
	{
		menu();
		printf("请输入你的操作:");
		int status = read_numbers(&input, 1);
		if (status < 0)
		{
			printf("输入已结束，游戏结束。\n");
			break;
		}
		if (status == 0)
		{
			printf("输入错误，请重新再试。菜单只能输入0或1。\n");
			input = -1;
			continue;
		}
		switch (input)
		{
		case 0:
				printf("游戏结束\n");
				break;
		case 1:
				    if (!game())
						input = 0;
				break;
		default:
				    printf("输入错误，请重新再试。菜单只能输入0或1。\n");
				break;
		}

	} while (input);
#ifdef _WIN32
	if (old_output_cp != 0)
		SetConsoleOutputCP(old_output_cp);
	if (old_input_cp != 0)
		SetConsoleCP(old_input_cp);
#endif
	return 0;
}
