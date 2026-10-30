#pragma once
//·负责功能函数的声明·负责部分常量的定义
#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#define ROW 3
#define COL 3
void init_board(char board[ROW][COL], int row, int col);
void print_board(char board[ROW][COL], int row, int col);
/* 返回1表示成功落子，0表示输入结束或棋盘参数异常。 */
int palyer_move(char board[ROW][COL], int row, int col);
char is_win(char board[ROW][COL], int row, int col);
void pc_move(char board[ROW][COL], int row, int col);
/* 整行读取1或2个整数：1成功，0输入错误，-1输入结束/读取失败。 */
int read_numbers(int numbers[], int count);
