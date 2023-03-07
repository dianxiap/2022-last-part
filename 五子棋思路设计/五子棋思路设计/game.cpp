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

//��ӡ����
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

//���1����
void player1Move(char board[ROW][COL], int row, int col)
{
	int x = 0;
	int y = 0;
	while (1)
	{
		printf("����������->");
		scanf("%d %d", &x, &y);
		if (x >= 1 && x <= row && y >= 1 && y <= col)
		{
			if (board[x - 1][y - 1] == ' ')
			{
				board[x - 1][y - 1] = '*';
				break;
			}
			else printf("�������ѱ�ռ�ã�����������->\n");
		}
		else
		{
			printf("�������̷�Χ������������->\n");
		}
	}
}
//���2����
void player2Move(char board[ROW][COL], int row, int col)
{
	int x = 0;
	int y = 0;
	while (1)
	{
		printf("����������->");
		scanf("%d %d", &x, &y);
		if (x >= 1 && x <= row && y >= 1 && y <= col)
		{
			if (board[x - 1][y - 1] == ' ')
			{
				board[x - 1][y - 1] = '#';
				break;
			}
			else printf("�������ѱ�ռ�ã�����������->\n");
		}
		else
		{
			printf("�������̷�Χ������������->\n");
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
//ʤ��
char isWin(char board[ROW][COL], int row, int col)
{
	int i = 0;
	int j = 0;
	
	for (i = 0; i < row; i++)
	{
		for (j = 0; j < col; j++)
		{
			if (board[i][j] == ' ')continue;
			//�ж���
			if (j < col - 4)
			{
				
				if (board[i][j] == board[i][j + 1] && board[i][j] == board[i][j + 2] && board[i][j] == board[i][j + 3] && board[i][j] == board[i][j + 4])
					return board[i][j];
			}
			//�ж���
			if (i < row - 4)
			{
				if (board[i][j] == board[i + 1][j] && board[i][j] == board[i + 2][j] && board[i][j] == board[i + 3][j] && board[i][j] == board[i + 4][j])
				{
					return board[i][j];
				}
			}
			//�ж����Խ���
			if (i < row - 4 && j < col - 4)
			{
				if (board[i][j] == board[i + 1][j + 1] && board[i][j] == board[i + 2][j + 2] && board[i][j] == board[i + 3][j + 3] && board[i][j] == board[i + 4][j + 4])
				{
					return board[1][j];
				}
			}
			//�жϸ��Խ���
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