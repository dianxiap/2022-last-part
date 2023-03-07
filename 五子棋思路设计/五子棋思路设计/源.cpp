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

	//����
	while (1)
	{
		//flagΪ�������1����
		if (flag % 2)
		{
			player1Move(board, ROW, COL);
			showMap(board, ROW, COL);

			ret = isWin(board, ROW, COL);
			if (ret != 'c')break;
		}
		//flagΪż�����2����
		else
		{
			player2Move(board, ROW, COL);
			showMap(board, ROW, COL);

			ret = isWin(board, ROW, COL);
			if (ret != 'c')break;
		}
		flag++;
	}

	if (ret == '*')printf("���1ʤ��\n");
	else if (ret == '#')printf("���2ʤ��\n");
	else if (ret == 'Q')printf("ƽ��\n");
}

int main()
{
	int input = 0;
	do
	{
		menu();
		printf("��ѡ��->");
		scanf("%d", &input);
		switch (input)
		{
		case 1:game(); break;
		case 0:printf("�˳���Ϸ\n"); break;
		default:printf("ѡ�����������ѡ��\n"); break;
		}
	} while (input);
}
