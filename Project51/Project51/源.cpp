#define _CRT_SECURE_NO_WARNINGS 1
#include <easyx.h>
#include <stdio.h>
#include <math.h>

void fivePointedStar(int x, int y, int radius, double startAngle)
{
	double delta = 2 * 3.14 / 5;

	POINT points[5];
	for (int i = 0;i < 5;i++)
	{
		points[i].x = cos(startAngle + i * delta * 2) * radius+x;
		points[i].y = sin(startAngle + i * delta * 2) * radius+y;
	}
	solidpolygon(points, 5);
}
int main()
{
	initgraph(800, 600);
	setorigin(400, 300);
	setaspectratio(1, -1);

	setbkcolor(RGB(164, 225, 202));
	cleardevice();

	setfillcolor(RED);
	setpolyfillmode(WINDING);

	int x, y;
	int r = 200;
	double theta = 0;
	double dtheta = 0.05;

	double startangle = 3.14 / 2;
	double dstartangle = 0.05;

	while (1)
	{
		x = cos(theta) * r;
		y = sin(theta) * r;
		cleardevice();
		fivePointedStar(x, y, 50,startangle);
		Sleep(40);
		theta -= dtheta;
		startangle += dstartangle;
	}

	getchar();
	closegraph();

}