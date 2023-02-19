#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
using namespace std;

const int N = 5010;
int f[N][N];

int main()
{
    int n, r;
    int max_x, max_y;
    cin >> n >> r;
    r = min(r, 5001);  //爆炸范围超过5001就覆盖了所有目标，因此只考虑r内就可以
    max_x = max_y = r;  //防止取不到最右下角的点
    for (int i = 0; i < n; i++)
    {
        int x = 0, y = 0, w = 0;
        cin >> x >> y >> w;
        f[++x][++y] += w;
        max_x = max(x, max_x);
        max_y = max(y, max_y);
    }
    for (int i = 1; i <= max_x; i++)
        for (int j = 1; j <= max_y; j++)
            f[i][j] += f[i - 1][j] + f[i][j - 1] - f[i - 1][j - 1];
    int ans = 0;
    //枚举所有边长是r的矩阵，枚举(i,j)为右下角
    for (int i = r; i <= max_x; i++)
        for (int j = r; j <= max_y; j++)
        {
            //(i,j)为右下角的点，(i-r+1,j-r+1)为左上角的点，带入子矩阵前缀和公式
            ans = max(ans, f[i][j] - f[i - r][j] - f[i][j - r] + f[i - r][j - r]);
        }
    cout << ans << endl;

}

