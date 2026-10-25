//负责功能函数的具体实现，包括具体逻辑
#include"game.h"
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
	for (int i = 0;i < row;i++)
	{
		for (int j = 0;j < col;j++)
		{
			printf(" %c ",board[i][j]);
			if (j < col - 1)
			{
				printf("|");
			}
		}
		printf("\n");
		for (int j = 0;j < col;j++)
			{
				pritnf("---");
				if (j < col - 1)
				{
					printf("|");
				}
			}
		}
	}
}
