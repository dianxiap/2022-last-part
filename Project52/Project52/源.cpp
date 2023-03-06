#define _CRT_SECURE_NO_WARNINGS 1
#include <easyx.h>
#include <stdio.h>
#include <conio.h>
#include <windows.h>
#include <stdlib.h>
#include <time.h>
typedef struct
{
	int x, y;
	int vx , vy ;  //x,y方向的分速度
	int r ;
	int barleft, bartop, barright, barbottom;
}GameData;

void reset(GameData* gdata)
{
	gdata->x = rand() % (400 + 1) - 200;
	gdata->y = rand() % (300 + 1) - 150;
	gdata->vx = 5;
	gdata->vy = 5;
	if (rand() % 2 == 0)
		gdata->vy = -gdata->vy;
	if (rand() % 2 == 0)
		gdata->vx = -gdata->vx;
	
	gdata->r = 20;
	gdata->barleft = -100;
	gdata->barright = 100;
	gdata->bartop = -280;
	gdata->barbottom = -300;
}

int main()
{
	initgraph(800, 600);
	setorigin(400, 300);
	setaspectratio(1, -1);
	setbkcolor(RGB(164,225,202));
	cleardevice();

	srand((unsigned int)time(NULL));

	GameData gdata;
	reset(&gdata);

	while (1)
	{
		cleardevice();
		solidcircle(gdata.x, gdata.y, gdata. r);

		solidrectangle(gdata.barleft, gdata.bartop, gdata.barright, gdata.barbottom);


		Sleep(10);
		if (gdata.y >= 300- gdata.r)gdata.vy = -gdata.vy;
		if (gdata.x >= 400- gdata.r || gdata.x <= -400+ gdata.r)gdata.vx = -gdata.vx;
		if (gdata.barleft<= gdata.x&& gdata.x<= gdata.barright&& gdata.y<= gdata.bartop+ gdata.r)gdata.vy = -gdata.vy;
		
		gdata.x += gdata.vx;
		gdata.y += gdata.vy;

		if (_kbhit() != 0)
		{
			char c = _getch();
			if (c == 'a')
			{
				if (gdata.barleft > -400)
				{
					gdata.barleft -= 15;
					gdata.barright -= 15;
				}
			}
			else if (c == 'd')
			{
				if (gdata.barright <400)
				{
					gdata.barleft += 15;
					gdata.barright += 15;
				}
			}
		}
		if (gdata.y <= -300)
		{
			reset(&gdata);
		}
	}
	getchar();
	closegraph();
}