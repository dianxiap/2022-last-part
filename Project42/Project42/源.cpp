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
    r = min(r, 5001);  //��ը��Χ����5001�͸���������Ŀ�꣬���ֻ����r�ھͿ���
    max_x = max_y = r;  //��ֹȡ���������½ǵĵ�
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
    //ö�����б߳���r�ľ���ö��(i,j)Ϊ���½�
    for (int i = r; i <= max_x; i++)
        for (int j = r; j <= max_y; j++)
        {
            //(i,j)Ϊ���½ǵĵ㣬(i-r+1,j-r+1)Ϊ���Ͻǵĵ㣬�����Ӿ���ǰ׺�͹�ʽ
            ans = max(ans, f[i][j] - f[i - r][j] - f[i][j - r] + f[i - r][j - r]);
        }
    cout << ans << endl;

}

