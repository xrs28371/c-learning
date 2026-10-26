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
void palyer_move(char board[ROW][COL], int row, int col);
char is_win(char board[ROW][COL], int row, int col);
void pc_move(char board[ROW][COL], int row, int col);