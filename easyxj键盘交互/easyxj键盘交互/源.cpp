#define _CRT_SECURE_NO_WARNINGS 1
#include <easyx.h>
#include <stdio.h>
#include <conio.h>
#include <Windows.h>
#include <math.h>

void linearMotion(int x1, int y1, int x2, int y2, int v)
{
	double tanTheta = (double)abs(y2 - y1) / (double)abs(x2 - x1);
	double theta = atan(tanTheta);

	double vy = sin(theta) * v;
	double vx = cos(theta) * v;

	int vxf = 0;
	int vyf = 0;
	if (x2 - x1 > 0)vxf = 1;
	else if (x2 - x1 < 0)vxf = -1;
	if (y2 - y1 > 0)vyf = 1;
	else if (y2 - y1 < 0)vyf = -1;
	vx *= vxf;
	vy *= vyf;

	double x, y;
	x = x1;
	y = y1;
	while (1)
	{
		cleardevice();
		solidcircle(x, y, 25);
		Sleep(40);
		x += vx;
		y += vy;

		if (vxf == 1)
		{
			if (x >= x2)
				break;
		}
		else if (vxf == -1)
		{
			if (x <= x2)
				break;
		}
		if(vyf == 1)
		{
			if (y >= y2)
				break;
		}
		else if (vyf == -1)
		{
			if (y <= y2)
				break;
		}
	}
}
int main()
{
	initgraph(800, 600);
	setorigin(400, 300);
	setaspectratio(1, -1);
	
	setbkcolor(RGB(164, 225, 202));
	cleardevice();

	linearMotion(-200, -200, 0, 200,5);
	linearMotion(0, 200, 200., -200,5);
	linearMotion(-200, -200, 0, 200, 5);
	getchar();
	closegraph();
}