#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
using namespace std;

const int N = 101;
int a[N][N];

int main()
{
    int W, H, n, R;
    cin >> W >> H >> n >> R;
    while (n--)
    {
        int x, y;
        cin >> x >> y;
        int x_l = max(0, x - R);
        int x_r = min(W, x + R);
        int y_down = max(0, y - R);
        int y_up = min(H, y + R);
        for (int s = x_l; s <= x_r; s++)
            for (int t = y_down; t <= y_up; t++)
            {
                int d = (s - x) * (s - x) + (t - y) * (t - y);
                if (d <= R * R)a[s][t] = 1;
            }
    }
    int res = 0;
    for (int i = 0; i <= W; i++)
        for (int j = 0; j <= H; j++)
            if (a[i][j] == 1)res++;
    cout << res;
}