#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <easyx.h>
#include <graphics.h>
#include <math.h>

#define key_down(VK_NONAME) ((GetAsyncKeyState(VK_NONAME) & 0x8000) ? 1:0)	//��ⰴ������ 

double dis(int s1x, int s1y, int s2x, int s2y) {	//����֮��ľ���
	double a, b, c;
	a = abs(s1x - s2x);
	b = abs(s1y - s2y);
	c = sqrt(a * a + b * b);
	return c;
}

int main()
{
	ExMessage m=getmessage();
	
	int x = m.x, y = m.y;		//��һ�����λ��
	int lastc = 1;				//��һ���������
	bool keydown = false;		//��һ����갴��

	initgraph(860, 640);
	setbkcolor(RGB(50, 50, 50));
	cleardevice();				//��ʼ������
	while (1)
	{
		m = getmessage();			//��ȡһ�������Ϣ
		if (key_down(VK_LBUTTON))	//�����
		{
			if (!keydown)x = m.x, y = m.y, keydown = true;

			//���ݶ����ٶ�ȷ���ʷ�
			if (dis(x, y, m.x, m.y) > lastc)lastc++;
			else lastc--;

			if (lastc < 1)lastc = 1;
			if (lastc > 25)lastc = 25;

			//����
			setlinestyle(PS_SOLID, lastc);
			setcolor(CYAN);
			line(m.x, m.y, x, y);

			x = m.x, y = m.y;
		}
		else keydown = false;
	}
	return 0;
}

