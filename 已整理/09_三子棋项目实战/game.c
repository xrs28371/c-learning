//负责功能函数的具体实现，包括具体逻辑
#include"game.h"
#include <stdio.h>
static int is_full(char board[ROW][COL], int row, int col);
void init_board(char board[ROW][COL], int row, int col)
{
	for (int i = 0;i < row;i++)
	{
		for (int j = 0;j < col;j++)
		{
			board[i][j] = ' ';
		}
	}
}
void print_board(char board[ROW][COL], int row, int col)
{
	//打印三轮，每一轮是两组
	for (int i = 0;i < row;i++)
	{
		//第一组
		for (int j = 0;j < col;j++)
		{
			printf(" %c ", board[i][j]);
			if (j < col - 1)
			{
				printf("|");
			}
		}
		printf("\n");
		//第2组
		if (i < row - 1)
		{
			for (int j = 0;j < col;j++)
			{
				printf("---");
				if (j < col - 1)
				{
					printf("|");
				}
			}
			printf("\n");
		}
		
	}
	

}
void palyer_move(char board[ROW][COL], int row, int col)
{
	printf("玩家移动\n");
	while (1)
	{
		printf("请输入你要落子的下标位置，以空格分开：\n");
		int x = 0;
		int y = 0;
		scanf("%d %d", &x, &y);
		if (x >= 1 && x <= row&&y>=1&&y<=col)
		{
			//1.检查这个下标有没有被落子
			if (board[x - 1][y - 1] == ' ')
			{
				board[x - 1][y - 1] = '*';
				break;
			}
			else
			{
				printf("该位置已经被落子了\n");
			}
		}
		else
		{
			printf("输入的下标是不合法的\n");
		}
	}

}
char is_win(char board[ROW][COL], int row, int col)
{
	//行
	for (int i = 0;i < row;i++)
	{
		if (board[i][0] == board[i][1] && board[i][1] == board[i][2] && board[i][0] != ' ')
		{
			return board[i][0];
		}
	}
	//列
	for (int j = 0;j < col;j++)
	{
		if (board[0][j] == board[1][j] && board[1][j] == board[2][j] && board[0][j] != ' ')
		{
			return board[0][j];
		}
	}

	//对角线
	if (board[0][0] == board[1][1] && board[1][1] == board[2][2] && board[0][0] != ' ')
	{
		return board[0][0];
	}
	if (board[0][2] == board[1][1] && board[1][1] == board[2][0] && board[0][0] != ' ')
	{
		return board[0][2];
	}
	//检查平局和失败的问题
	//如果走到这一行，说明没有出现空格外一样的情况，现在只需要检查当时满还是不满
	if (is_full(board, row, col))
	{
		return'Q';//表示平局
	}
	//没有人赢，且没有平局
	return'C';//继续

}

static int is_full(char board[ROW][COL], int row, int col)//只服务于这个game.c
{
	for (int i = 0;i < row;i++)
	{
		for (int j = 0;j < col;j++)
		{
			if (board[i][j] == ' ')
			{
				return 0;//没有满
			}
		}
	}
	return 1;//满了
}
void pc_move(char board[ROW][COL], int row, int col)
{
	printf("电脑移动\n");
	while (1)
	{
		srand((unsigned int)time(NULL));
		int x = rand()%row;//0到row
		int y = rand()%col;//0到col

		if (board[x][y] == ' ')
		{
			board[x][y] = '#';
			break;
		}
	}
}