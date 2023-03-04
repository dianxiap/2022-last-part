#define _CRT_SECURE_NO_WARNINGS 1
#include <easyx.h>
#include <stdio.h>
#include <math.h>
#define PI 3.14

int main()
{
	initgraph(800, 600);
	setorigin(400, 300);
	setaspectratio(1, -1);
	
	setbkcolor(WHITE);
	cleardevice();
	setlinecolor(RED);
	setlinestyle(PS_DASH, 12);

	setfillcolor(BROWN);
	fillcircle(00, 0, 200);
	getchar();
	closegraph();
}