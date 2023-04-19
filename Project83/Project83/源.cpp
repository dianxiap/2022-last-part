#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
#include <cstring>
#include <algorithm>
#include <unordered_map>

using namespace std;

const int N = 100010;

// ��¼ĳ���ַ�����״̬����2*4����ӳ����ַ�������û���߹�
unordered_map<string, int> dist;
// ��¼ĳ���ַ���������ǰ���������ABC����һ��������ǰ���ַ�����ʲô
unordered_map<string, pair<char, string>> pre;

string start = "12345678";  // ��ʼ״̬
string ed;                // Ŀ��״̬
string q[N];              // ����

// ������������
string A(string t)
{
    // 1234 5378  -> 8765 4321
    for (int i = 0; i < 4; i++)swap(t[i], t[7 - i]);
    return t;
}

// �����һ�в��뵽�����
string B(string t)
{
    // 1234 5678  -> 4123 6785
    for (int i = 3; i > 0; i--)swap(t[i], t[i - 1]);
    for (int i = 4; i < 7; i++)swap(t[i], t[i + 1]);
    return t;
}

// ħ�������4����˳ʱ����ת
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

        // ABC������������ַ���
        string m[3] = { A(t),B(t),C(t) };

        for (int i = 0; i < 3; i++)
        {
            string x = m[i];
            // û���߹�
            if (!dist.count(x))
            {
                q[++tt] = x;
                dist[x] = dist[t] + 1;
                // x��ǰ��t����ͨ����A'+i�ķ�ʽת��������
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

    // ��̲������еĳ���
    cout << dist[ed] << endl;

    string res;

    // ���·��
    if (dist[ed])
    {
        while (1)
        {
            if (ed == start)break;
            // ��¼����ǰ������������ż�¼�ģ����Ҫ������״̬��ʼ��
            res += pre[ed].first;
            ed = pre[ed].second;
        }
    }
    // ���������Ǵ���ʼ̬��Ŀ��̬��·��
    reverse(res.begin(), res.end());
    cout << res;
}