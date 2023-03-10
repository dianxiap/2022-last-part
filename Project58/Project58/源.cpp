#define _CRT_SECURE_NO_WARNINGS 1
#include <graphics.h>
#include <stdio.h>
#include <iostream>
#include <algorithm>
#include <easyx.h>
#include<conio.h>

COLORREF current_color = RGB(255, 0, 0);
COLORREF colors[] = { RGB(255, 0, 0), RGB(255, 192, 203), RGB(0, 0, 0), RGB(255, 255, 255) };
int color_index = 0;


int main()
{
	initgraph(800, 600);
	setbkcolor(WHITE);
	cleardevice();
	MOUSEMSG m;
	int size = 1;

	bool dring = false;
	while (1)
	{
		m = GetMouseMsg();			//获取一条鼠标消息
		switch (m.uMsg)
		{
		case WM_MOUSEMOVE:
			if (dring)
			{
				setlinecolor(current_color);
				setfillcolor(current_color);
				fillcircle(m.x, m.y, size);
			}
			break;
		case WM_LBUTTONDOWN:
			dring = true;
			break;
		case WM_LBUTTONUP:
			dring = false;
			break;
		}
		if (_kbhit()) {
			int key = _getch();
			switch (key) {
			case 'a':
				color_index = (color_index + 1) % 4;
				current_color = colors[color_index];
				break;
			case 'd':
				color_index = (color_index + 3) % 4;
				current_color = colors[color_index];
				break;
			case 'q':
				size = max(1, size - 1);
				break;
			case 'e':
				size = min(25, size + 1);
				break;
			}
		}
	}
	getchar();
	closegraph();
	return 0;
}
