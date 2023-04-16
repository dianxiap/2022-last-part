#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
using namespace std;

const int N = 1010;
const int INF = 0x3f3f3f3f;

int n, m, k;
int w[N][N];
// row_max[i]长度为k的行区间的最大值
// row_min[i]长度为k的列区间的最小值（要把列映射成行）
int row_min[N][N], row_max[N][N];
int q[N];

// 对于每个一维的数组中的数字，找出包括自己在内，长度最长为k的范围内，最小值是多少
void get_min(int a[], int b[], int tot)
{
    int hh = 0, tt = -1;
    for (int i = 1; i <= tot; i++)
    {
        // 这种区间边界最好模拟一下：
        // 假设i=5,k=3,则窗口范围：[3,4,5]
        // 下标从i-k+1开始
        while (hh <= tt && q[hh] < i - k + 1)hh++;
        while (hh <= tt && a[q[tt]] >= a[i])tt--;
        q[++tt] = i;
        b[i] = a[q[hh]];
    }

}
// 对于每个一维的数组中的数字，找出包括自己在内，长度最长为k的范围内，最大值是多少
void get_max(int a[], int b[], int tot)
{
    int hh = 0, tt = -1;
    for (int i = 1; i <= tot; i++)
    {
        while (hh <= tt && q[hh] < i - k + 1)hh++;
        while (hh <= tt && a[q[tt]] <= a[i])tt--;
        q[++tt] = i;
        b[i] = a[q[hh]];
    }
}

int main()
{
    cin >> n >> m >> k;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
            cin >> w[i][j];

    // 预处理：先遍历每一行，记录范围k内的最大值与最小指
    for (int i = 1; i <= n; i++)
    {
        get_min(w[i], row_min[i], m);
        get_max(w[i], row_max[i], m);
    }

    int t[N]; // 将列转为行，方便计算
    int a[N]; // 最小值数组
    int b[N]; // 最大值数组

    int res = INF;

    // 遍历列，从k开始，直接找第一个k范围的最大最小
    for (int j = k; j <= m; j++)
    {
        // 同一列的每一行，转为一列
        for (int i = 1; i <= n; i++)t[i] = row_min[i][j];
        get_min(t, a, n);

        for (int i = 1; i <= n; i++)t[i] = row_max[i][j];
        get_max(t, b, n);

        for (int i = k; i <= n; i++)res = min(res, b[i] - a[i]);
    }
    cout << res;
}