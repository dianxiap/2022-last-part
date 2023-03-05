#define _CRT_SECURE_NO_WARNINGS 1
#include <easyx.h>
#include <windows.h>
#include <stdio.h>
#define PI 3.14

int main()
{
	initgraph(1024, 1024);
	setbkcolor(WHITE);
	cleardevice();

	setlinecolor(BLACK);  //√Ë±ﬂ—’…´
	setlinestyle(PS_SOLID,10);  //√Ë±ﬂ–Œ Ω£¨¥÷œ∏

	setfillcolor(BLUE);  //ÃÓ≥‰—’…´
	fillellipse(118, 125, 990, 931);  //¥¯√Ë±ﬂÃÓ≥‰ ΩÕ÷‘≤
	Sleep(1000);

	setfillcolor(WHITE);
	fillellipse(189, 271, 919, 931);
	Sleep(1000);

	fillellipse(375, 170, 555, 420);
	fillellipse(555, 170, 735, 420);
	Sleep(1000);

	setfillcolor(BLACK);
	solidcircle(484, 333, 25);  
	solidcircle(617, 333, 25);
	Sleep(1000);

	setfillcolor(WHITE);
	solidcircle(484, 333, 10);  //Œﬁ±ﬂøÚµƒÃÓ≥‰‘≤
	solidcircle(617, 333, 10);
	Sleep(1000);

	setfillcolor(RED);
	fillcircle(554, 420, 35);   //”–±ﬂøÚµƒÃÓ≥‰‘≤
	Sleep(1000);
	line(554, 460, 554, 828);
	Sleep(1000);

	arc(320, 510, 789, 827, PI, 2 * PI);  //‘≤ª°
	Sleep(1000);

	line(125, 313, 296, 410);
	Sleep(500);
	line(83, 444, 270, 474);
	Sleep(500);
	line(83, 595, 262, 527);
	Sleep(500);
	line(819, 414, 990, 320);
	Sleep(500);
	line(845, 478, 1029, 448);
	Sleep(500);
	line(853, 542, 1029, 660);
	getchar();
	closegraph();
}