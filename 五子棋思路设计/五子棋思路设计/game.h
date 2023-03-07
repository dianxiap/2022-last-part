#pragma once
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>


#define ROW 10
#define COL 10

//char board[ROW][COL];

//初始化
void initBoard(char board[ROW][COL],int row,int col);
//打印棋盘
void showMap(char board[ROW][COL],int row,int col);
//玩家1下棋
void player1Move(char board[ROW][COL], int row, int col);
//玩家2下棋
void player2Move(char board[ROW][COL], int row, int col);
//胜利
char isWin(char board[ROW][COL], int row, int col);
//判断棋盘是否已满
int is_full(char board[ROW][COL], int row, int col);

