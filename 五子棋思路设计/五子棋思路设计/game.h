#pragma once
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>


#define ROW 10
#define COL 10

//char board[ROW][COL];

//��ʼ��
void initBoard(char board[ROW][COL],int row,int col);
//��ӡ����
void showMap(char board[ROW][COL],int row,int col);
//���1����
void player1Move(char board[ROW][COL], int row, int col);
//���2����
void player2Move(char board[ROW][COL], int row, int col);
//ʤ��
char isWin(char board[ROW][COL], int row, int col);
//�ж������Ƿ�����
int is_full(char board[ROW][COL], int row, int col);

