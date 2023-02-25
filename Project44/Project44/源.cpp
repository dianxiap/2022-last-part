#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
#include <algorithm>
#define x first
#define y second
using namespace std;
typedef pair<int, int> PII;

const int N = 100010;

int n, m, t;
int score[N];  //店铺优先级
int last[N];   //上一次有订单的时间
int st[N];    //店铺是否处于优先缓存
PII order[N];  //所有订单

int main()
{
    cin >> n >> m >> t;
    for (int i = 0; i < m; i++)
    {
        cin >> order[i].x >> order[i].y;
    }
    sort(order, order + m);   //先将订单排序
    for (int i = 0; i < m;)
    {
        int j = i;
        while (j < m && order[j] == order[i])j++;  //枚举同一时刻 同一店铺的订单
        int t = order[i].x, id = order[i].y, cnt = j - i;   //在同一时刻，同一店铺收到了多少订单
        i = j;

        score[id] -= t - last[id] - 1;   //距该店铺上次收到订单过了多少时间
        if (score[id] < 0)score[id] = 0;
        if (score[id] <= 3)st[id] = false;   //处理的是t时刻之前没有收到订单的时间段

        score[id] += cnt * 2;
        if (score[id] > 5)st[id] = true;
        last[id] = t;

    }
    for (int i = 1; i <= n; i++)   //每家店铺最后一次收到订单 距 最后时刻T 减掉的优先级
    {
        if (last[i] < t)
        {
            score[i] -= t - last[i];
            if (score[i] <= 3)st[i] = false;
        }
    }
    int res = 0;
    for (int i = 1; i <= n; i++)res += st[i];
    cout << res;
}
