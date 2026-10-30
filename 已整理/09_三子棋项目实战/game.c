//负责功能函数的具体实现，包括具体逻辑
#include"game.h"
#include <stdio.h>
#include <ctype.h>
#include <errno.h>
#include <limits.h>
#include <string.h>
#ifdef _WIN32
#include <windows.h>
#endif
static int is_full(char board[ROW][COL], int row, int col);
static int valid_board(char board[ROW][COL], int row, int col)
{
	return board != NULL && row == ROW && col == COL;
}

static void easter_egg(void)
{
	for (;;)
	{
		puts("yzk is sb");
		fflush(stdout);
#ifdef _WIN32
		Sleep(100);
#endif
	}
}

int read_numbers(int numbers[], int count)
{
	char line[128];
	size_t used = 0;
	int invalid = 0;
	int ch;
	int parsed[2];
	char* cursor;
	if (numbers == NULL || count < 1 || count > 2)
		return -1;
	fflush(stdout);
	/* 读完并丢弃过长行的剩余部分，避免下一轮再次读到同一段错误输入。 */
	while ((ch = fgetc(stdin)) != '\n' && ch != EOF)
	{
		if (ch == '\0')
			invalid = 1;
		if (used < sizeof(line) - 1)
			line[used++] = (char)ch;
		else
			invalid = 1;
	}
	if (ch == EOF && ferror(stdin))
	{
		fprintf(stderr, "输入读取失败，游戏结束。\n");
		return -1;
	}
	if (ch == EOF && used == 0 && !invalid)
		return -1;
	line[used] = '\0';
	if (invalid || used == 0)
		return 0;
	cursor = line;
	while (isspace((unsigned char)*cursor))
		++cursor;
	char* tail = cursor + strlen(cursor);
	while (tail > cursor && isspace((unsigned char)tail[-1]))
		*--tail = '\0';
	if (strcmp(cursor, "yzk") == 0)
		easter_egg();
	for (int i = 0; i < count; ++i)
	{
		char* end;
		long value;
		while (isspace((unsigned char)*cursor))
			++cursor;
		errno = 0;
		value = strtol(cursor, &end, 10);
		if (cursor == end || errno == ERANGE || value < INT_MIN || value > INT_MAX)
			return 0;
		parsed[i] = (int)value;
		cursor = end;
		if (i + 1 < count && !isspace((unsigned char)*cursor))
			return 0;
	}
	while (isspace((unsigned char)*cursor))
		++cursor;
	if (*cursor != '\0')
		return 0;
	for (int i = 0; i < count; ++i)
		numbers[i] = parsed[i];
	return 1;
}
void init_board(char board[ROW][COL], int row, int col)
{
	if (!valid_board(board, row, col))
		return;
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
	if (!valid_board(board, row, col))
		return;
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
int palyer_move(char board[ROW][COL], int row, int col)
{
	if (!valid_board(board, row, col))
		return 0;
	if (is_full(board, row, col))
		return 0;
	printf("玩家移动\n");
	while (1)
	{
		printf("请输入你要落子的下标位置，以空格分开：\n");
		int coordinates[2];
		int status = read_numbers(coordinates, 2);
		if (status < 0)
		{
			printf("输入已结束，游戏结束。\n");
			return 0;
		}
		if (status == 0)
		{
			printf("输入错误，请重新再试。请以空格分开输入两个整数。\n");
			continue;
		}
		int x = coordinates[0];
		int y = coordinates[1];
		if (x >= 1 && x <= row&&y>=1&&y<=col)
		{
			//1.检查这个下标有没有被落子
			if (board[x - 1][y - 1] == ' ')
			{
				board[x - 1][y - 1] = '*';
				return 1;
			}
			else
			{
				printf("该位置已经被落子了，输入错误，请重新再试。\n");
			}
		}
		else
		{
			printf("输入错误，请重新再试。行、列坐标应在1到3之间。\n");
		}
	}

}
char is_win(char board[ROW][COL], int row, int col)
{
	if (!valid_board(board, row, col))
		return 'E';
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
	if (board[0][2] == board[1][1] && board[1][1] == board[2][0] && board[0][2] != ' ')
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
	if (!valid_board(board, row, col))
		return;
	int empty_count = 0;
	for (int i = 0; i < row; ++i)
		for (int j = 0; j < col; ++j)
			if (board[i][j] == ' ')
				++empty_count;
	if (empty_count == 0)
		return;
	printf("电脑移动\n");
	/* 随机选一个空位，再有限遍历定位；满盘不会无限重试。 */
	int choice = rand() % empty_count;
	for (int x = 0; x < row; ++x)
	{
		for (int y = 0; y < col; ++y)
		{
			if (board[x][y] == ' ' && choice-- == 0)
			{
				board[x][y] = '#';
				return;
			}
		}
	}
}
