#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <easyx.h>
#include <graphics.h>
#include <math.h>

#define key_down(VK_NONAME) ((GetAsyncKeyState(VK_NONAME) & 0x8000) ? 1:0)	//检测按键按下 

double dis(int s1x, int s1y, int s2x, int s2y) {	//两点之间的距离
	double a, b, c;
	a = abs(s1x - s2x);
	b = abs(s1y - s2y);
	c = sqrt(a * a + b * b);
	return c;
}

int main()
{
	ExMessage m=getmessage();
	
	int x = m.x, y = m.y;		//上一次鼠标位置
	int lastc = 1;				//上一次两点距离
	bool keydown = false;		//上一次鼠标按下

	initgraph(860, 640);
	setbkcolor(RGB(50, 50, 50));
	cleardevice();				//初始化窗口
	while (1)
	{
		m = getmessage();			//获取一条鼠标消息
		if (key_down(VK_LBUTTON))	//鼠标点击
		{
			if (!keydown)x = m.x, y = m.y, keydown = true;

			//根据动笔速度确定笔锋
			if (dis(x, y, m.x, m.y) > lastc)lastc++;
			else lastc--;

			if (lastc < 1)lastc = 1;
			if (lastc > 25)lastc = 25;

			//绘制
			setlinestyle(PS_SOLID, lastc);
			setcolor(CYAN);
			line(m.x, m.y, x, y);

			x = m.x, y = m.y;
		}
		else keydown = false;
	}
	return 0;
}

