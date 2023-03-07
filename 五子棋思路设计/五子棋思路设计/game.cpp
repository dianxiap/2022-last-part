#define _CRT_SECURE_NO_WARNINGS 1
#include "game.h"

void initBoard(char board[ROW][COL], int row, int col)
{
	for (int i = 0; i < row; i++)
	{
		for (int j = 0; j < col; j++)
		{
			board[i][j] = ' ';
		}
	}
}

//打印棋盘
void showMap(char board[ROW][COL], int row, int col)
{
	for (int i = 0; i < row; i++)
	{
		for (int j = 0; j < col; j++)
		{
			printf(" %c ", board[i][j]);
			if (j < col - 1)printf("|");
		}
		printf("\n");
		if (i < row - 1)
		{
			for (int j = 0; j < col; j++)
			{
				printf("---");
				if (j < col - 1)printf("|");
			}
		}
		printf("\n");
	}
}

//玩家1下棋
void player1Move(char board[ROW][COL], int row, int col)
{
	int x = 0;
	int y = 0;
	while (1)
	{
		printf("请输入坐标->");
		scanf("%d %d", &x, &y);
		if (x >= 1 && x <= row && y >= 1 && y <= col)
		{
			if (board[x - 1][y - 1] == ' ')
			{
				board[x - 1][y - 1] = '*';
				break;
			}
			else printf("该坐标已被占用，请重新输入->\n");
		}
		else
		{
			printf("超出棋盘范围，请重新输入->\n");
		}
	}
}
//玩家2下棋
void player2Move(char board[ROW][COL], int row, int col)
{
	int x = 0;
	int y = 0;
	while (1)
	{
		printf("请输入坐标->");
		scanf("%d %d", &x, &y);
		if (x >= 1 && x <= row && y >= 1 && y <= col)
		{
			if (board[x - 1][y - 1] == ' ')
			{
				board[x - 1][y - 1] = '#';
				break;
			}
			else printf("该坐标已被占用，请重新输入->\n");
		}
		else
		{
			printf("超出棋盘范围，请重新输入->\n");
		}
	}
}
int is_full(char board[ROW][COL], int row, int col)
{
	int i = 0;
	int j = 0;
	for (i = 0; i < row; i++)
	{
		for (int j = 0; j < col; j++)
			if (board[i][j] == ' ')
				return 0;
	}
	return 1;
}
//胜利
char isWin(char board[ROW][COL], int row, int col)
{
	int i = 0;
	int j = 0;
	
	for (i = 0; i < row; i++)
	{
		for (j = 0; j < col; j++)
		{
			if (board[i][j] == ' ')continue;
			//判断行
			if (j < col - 4)
			{
				
				if (board[i][j] == board[i][j + 1] && board[i][j] == board[i][j + 2] && board[i][j] == board[i][j + 3] && board[i][j] == board[i][j + 4])
					return board[i][j];
			}
			//判断列
			if (i < row - 4)
			{
				if (board[i][j] == board[i + 1][j] && board[i][j] == board[i + 2][j] && board[i][j] == board[i + 3][j] && board[i][j] == board[i + 4][j])
				{
					return board[i][j];
				}
			}
			//判断主对角线
			if (i < row - 4 && j < col - 4)
			{
				if (board[i][j] == board[i + 1][j + 1] && board[i][j] == board[i + 2][j + 2] && board[i][j] == board[i + 3][j + 3] && board[i][j] == board[i + 4][j + 4])
				{
					return board[1][j];
				}
			}
			//判断副对角线
			if (i < row - 4 && j>4)
			{
				if (board[i][j] == board[i + 1][j - 1] && board[i][j] == board[i + 2][j - 2] && board[i][j] == board[i + 3][j - 3] && board[i][j] == board[i + 4][j - 4])
				{
					return board[i][j];
				}
			}
		}
		
	}
	if (is_full(board, row, col) == 1)return 'Q';
	return 'c';
}