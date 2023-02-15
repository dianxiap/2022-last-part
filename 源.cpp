#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
#include <cstring>

using namespace std;
const int N = 6;

char g[N][N], backup[N][N];
int n;
int dx[5] = { -1,0,1,0,0 }, dy[5] = { 0,1,0,-1,0 };

void turn(int x, int y)
{
    for (int i = 0; i < 5; i++)
    {
        int a = x + dx[i], b = y + dy[i];
        if (a < 0 || a >= 5 || b < 0 || b >= 5)continue;
        g[a][b] ^= 1;  //���ַ�0���ַ�1�����ַ�1���ַ�0
    }
}

int main()
{
    cin >> n;
    while (n--)
    {
        for (int i = 0; i < 5; i++)cin >> g[i];

        int res = 10;

        for (int i = 0; i < 32; i++)  //��00000����������11111��32�ַ���
        {
            memcpy(backup, g, sizeof g);

            int step = 0;

            for (int j = 0; j < 5; j++)  //�Ƚ��е�һ�еĲ���
            {
                if (i >> j & 1)   //��������1��һ�¿��أ����磺10100��20������2��4λ���ҵ���01234����Ҫ�������Ǵ������û����
                {
                    step++;
                    turn(0, 4 - j);
                }
            }

            //ÿһ�п��صĲ�������ȫ��ǰһ�еƵ�����״̬������
            for (int j = 0; j < 4; j++)  //���һ�в��ò�������ֹ����
            {
                for (int k = 0; k < 5; k++)
                {
                    if (g[j][k] == '0')
                    {
                        step++;
                        turn(j + 1, k);
                    }
                }
            }
            bool dark = false;
            for (int j = 0; j < 5; j++)
            {
                if (g[4][j] == '0')
                {
                    dark = true;  //���һ�������ߵĵ�
                }
            }
            if (!dark)res = min(res, step);
            memcpy(g, backup, sizeof backup);
        }
        if (res > 6)res = -1;
        cout << res << endl;;
    }
}