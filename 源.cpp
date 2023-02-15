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
        g[a][b] ^= 1;  //从字符0到字符1，从字符1到字符0
    }
}

int main()
{
    cin >> n;
    while (n--)
    {
        for (int i = 0; i < 5; i++)cin >> g[i];

        int res = 10;

        for (int i = 0; i < 32; i++)  //从00000————到11111的32种方案
        {
            memcpy(backup, g, sizeof g);

            int step = 0;

            for (int j = 0; j < 5; j++)  //先进行第一行的操作
            {
                if (i >> j & 1)   //如果结果是1按一下开关，比如：10100（20），第2、4位（右到左01234）需要按，不是代表灯有没有亮
                {
                    step++;
                    turn(0, 4 - j);
                }
            }

            //每一行开关的操作，完全被前一行灯的亮灭状态所决定
            for (int j = 0; j < 4; j++)  //最后一行不用操作，防止覆盖
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
                    dark = true;  //最后一行有灭者的等
                }
            }
            if (!dark)res = min(res, step);
            memcpy(g, backup, sizeof backup);
        }
        if (res > 6)res = -1;
        cout << res << endl;;
    }
}