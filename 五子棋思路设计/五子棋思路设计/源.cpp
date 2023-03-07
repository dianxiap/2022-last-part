#define _CRT_SECURE_NO_WARNINGS 1
#include "game.h"

void menu()
{
	printf("*********************\n");
	printf("******1.start********\n");
	printf("******0.exit  *******\n");
	printf("*********************\n");
}

void game()
{
	int flag = 0;
	char ret = 'c';
	char board[ROW][COL];
	initBoard(board, ROW, COL);
	showMap(board, ROW, COL);

	//下棋
	while (1)
	{
		//flag为奇数玩家1下棋
		if (flag % 2)
		{
			player1Move(board, ROW, COL);
			showMap(board, ROW, COL);

			ret = isWin(board, ROW, COL);
			if (ret != 'c')break;
		}
		//flag为偶数玩家2下棋
		else
		{
			player2Move(board, ROW, COL);
			showMap(board, ROW, COL);

			ret = isWin(board, ROW, COL);
			if (ret != 'c')break;
		}
		flag++;
	}

	if (ret == '*')printf("玩家1胜利\n");
	else if (ret == '#')printf("玩家2胜利\n");
	else if (ret == 'Q')printf("平局\n");
}

int main()
{
	int input = 0;
	do
	{
		menu();
		printf("请选择->");
		scanf("%d", &input);
		switch (input)
		{
		case 1:game(); break;
		case 0:printf("退出游戏\n"); break;
		default:printf("选择错误，请重新选择\n"); break;
		}
	} while (input);
}
