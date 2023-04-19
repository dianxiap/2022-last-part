#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
#include <cstring>
#include <algorithm>
#include <unordered_map>

using namespace std;

const int N = 100010;

// 记录某个字符串的状态（将2*4矩阵映射成字符串）有没有走过
unordered_map<string, int> dist;
// 记录某个字符串，它的前序操作符是ABC的哪一个，它的前序字符串是什么
unordered_map<string, pair<char, string>> pre;

string start = "12345678";  // 初始状态
string ed;                // 目标状态
string q[N];              // 队列

// 交换上下两行
string A(string t)
{
    // 1234 5378  -> 8765 4321
    for (int i = 0; i < 4; i++)swap(t[i], t[7 - i]);
    return t;
}

// 将最后一列插入到最左边
string B(string t)
{
    // 1234 5678  -> 4123 6785
    for (int i = 3; i > 0; i--)swap(t[i], t[i - 1]);
    for (int i = 4; i < 7; i++)swap(t[i], t[i + 1]);
    return t;
}

// 魔板中央的4个数顺时针旋转
string C(string t)
{
    swap(t[1], t[2]);    // 1234 5678 -> 1324 5678
    swap(t[5], t[6]);    // 1324 5678 -> 1324 5768
    swap(t[1], t[5]);    // 1324 5768 -> 1724 5368 
    return t;
}

void bfs()
{
    int hh = 0, tt = -1;
    q[++tt] = start;

    while (hh <= tt)
    {
        string t = q[hh++];

        if (t == ed)return;

        // ABC操作后的三种字符串
        string m[3] = { A(t),B(t),C(t) };

        for (int i = 0; i < 3; i++)
        {
            string x = m[i];
            // 没有走过
            if (!dist.count(x))
            {
                q[++tt] = x;
                dist[x] = dist[t] + 1;
                // x的前序：t，是通过‘A'+i的方式转化过来的
                pre[x] = { 'A' + i,t };
            }
        }
    }
}

int main()
{
    char x;
    for (int i = 0; i < 8; i++)cin >> x, ed += x;

    bfs();

    // 最短操作序列的长度
    cout << dist[ed] << endl;

    string res;

    // 输出路径
    if (dist[ed])
    {
        while (1)
        {
            if (ed == start)break;
            // 记录的是前序操作符，反着记录的，因此要从最后的状态开始找
            res += pre[ed].first;
            ed = pre[ed].second;
        }
    }
    // 翻过来才是从起始态到目标态的路径
    reverse(res.begin(), res.end());
    cout << res;
}