#define _CRT_SECURE_NO_WARNINGS 1

#include "contatc.h"

void menu()
{
	printf("********************\n");
	printf("****1.add     2.del****\n");
	printf("****3.search  4.modify****\n");
	printf("****5.show    6.sort****\n");
	printf("****0.exit      ****\n");
	printf("********************\n");
}
enum Option
{
	EXIT,//0
	ADD, //1
	DEL, //2
	SEARCH,
	MODIFY,
	SHOW,
	SORT
};
int main()
{
	int input = 0;
	Contact con;
	InitContact(&con);
	do
	{
		menu();
		printf("请选择:>");
		scanf("%d", &input);
		switch (input)
		{
		case ADD:
			AddContact(&con);
			break;
		case DEL:
			DelContact(&con);
			break;
		case SEARCH:
			SearchContact(&con);
			break;
		case MODIFY:
			ModifyContact(&con);
			break;
		case SHOW:
			ShowContact(&con);
			break;
		case SORT:
			ShowContact(&con);
			break;
		case EXIT:
			SaveContact(&con);
			DestroyContact(&con);
			printf("推出通讯录\n");
			break;
		default:
			printf("选择错误\n");
			break;
		}
	} while (input);
	return 0;
}