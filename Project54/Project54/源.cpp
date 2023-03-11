#define _CRT_SECURE_NO_WARNINGS 1
#include <easyx.h>
#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#define NODE_WIDTH 20
#include <conio.h>

//蛇节点
typedef struct
{
	int x, y;
}node;
//蛇头移动的方向
enum direction
{
	sup,
	sdown,
	sleft,
	sright
};
//蛇头移动
node snakemove(node* snake, int lenth, int direction)
{
	//记录尾节点的数据
	node tail = snake[lenth - 1];
	//覆盖蛇头数组，前一个节点覆盖后一个节点
	for (int i = lenth - 1; i; i--)
	{
		snake[i] = snake[i - 1];
	}
	//存储新的蛇头节点
	node newhead;
	newhead = snake[0];
	if (direction == sup)newhead.y--;
	else if (direction == sdown)newhead.y++;
	else if (direction == sleft)newhead.x -- ;
	else if (direction == sright)newhead.x++;
	snake[0] = newhead;
	return tail;
}
//绘制网格
void paint()
{
	for (int x = 0; x <= 800; x += NODE_WIDTH)
	{
		line(x, 0, x, 600);
	}

	for (int y = 0; y <= 600; y += NODE_WIDTH)
	{
		line(0, y, 800, y);
	}
}
//绘制蛇，n为蛇的节点个数
void paintSnake(node* snake, int n)
{
	int left, top, right, bottom;
	for (int i = 0; i < n; i++)
	{
		//左上，右下
		left = snake[i].x * NODE_WIDTH;
		top = snake[i].y * NODE_WIDTH;
		right = (snake[i].x+1) * NODE_WIDTH;
		bottom = (snake[i].y+1) * NODE_WIDTH;
		solidrectangle(left, top, right, bottom);
	}
}
//改变蛇头移动的方向,pD为当前蛇运动的方向
void changeDirection(enum direction* pD)
{
	if (_kbhit() != 0)
	{
		char c = _getch();
		switch(c)
		{
		case 'w':
			if(*pD!=sdown)
				*pD = sup; 
			break;
		case 's':
			if (*pD != sup)
				*pD = sdown; 
			break;
		case 'a':
			if (*pD != sright)
				*pD = sleft; 
			break;
		case 'd':
			if (*pD != sleft)
				*pD = sright; 
			break;
		}
	}
}
//生成食物,snake表示蛇身,len表示蛇节点个数
node createFood(node* snake, int len)
{
	node food;
	while (1)
	{
		food.x = rand() % (800 / NODE_WIDTH);
		food.y = rand() % (600 / NODE_WIDTH);
		int i = 0;
		for (i = 0; i < len; i++)
		{
			//食物在蛇身上
			if (snake[i].x == food.x && snake[i].y == food.y)break;
		}
		if (i < len)continue;
		else break;
	}
	return food;
}
//绘制食物
void paintfood(node food)
{
	int left, top, right, bottom;
	left = food.x * NODE_WIDTH;
	top = food.y * NODE_WIDTH;
	right = (food.x+1) * NODE_WIDTH;
	bottom = (food.y+1) * NODE_WIDTH;
	setfillcolor(YELLOW);
	solidrectangle(left, top, right, bottom);
	setfillcolor(WHITE);  
}
//游戏结束
bool isGameOver(node* snake, int len)
{
	//蛇头超出边界
	if (snake[0].x < 0 || snake[0].x>800 / NODE_WIDTH)
		return true;
	if (snake[0].y < 0 || snake[0].y>600 / NODE_WIDTH)
		return true;
	//蛇身坐标与蛇身坐标重合
	for (int i = 1; i < len; i++)
	{
		if (snake[0].x == snake[i].x && snake[0].y == snake[i].y)
			return true;
	}
	return false;
}
//
int main()
{
	initgraph(800, 600);
	setbkcolor(RGB(154, 225, 202));
	cleardevice();

	node snake[100] = { {5,7},{4,7},{3,7},{2,7},{1,7} };
	int lenth = 5;
	enum direction d = sright;

	//第一次生成食物
	srand((unsigned int)time(NULL));
	node food = createFood(snake, lenth);

	while (1)
	{
		cleardevice();
		paint();
		paintSnake(snake, lenth);
		paintfood(food);
		Sleep(100);
		
		changeDirection(&d);
		//保存蛇尾节点返回的数据
		node lastTail = snakemove(snake, lenth, d);
		//判断蛇头是否与食物节点重合
		if (snake[0].x == food.x && snake[0].y == food.y)
		{
			if (lenth < 100)
			{
				//重合就把移动过程中删除的尾节点加回去
				snake[lenth] = lastTail;
				lenth++;
			}
			food=createFood(snake, lenth);
		}
		//snakemove(snake, lenth, d);
	}
	 
	getchar();
	closegraph();

}