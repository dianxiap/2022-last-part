#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

const int N = 300010;

typedef pair<int, int>PII;

int a[N], s[N];

vector<int>alls;
vector<PII>add;
vector<PII>quary;

int n, m;

int find(int x)
{
    int l = 0, r = alls.size() - 1;
    while (l < r)
    {
        int mid = l + r >> 1;
        if (alls[mid] >= x)r = mid;
        else l = mid + 1;

    }
    return r + 1;
}

int main()
{
    cin >> n >> m;

    while (n--)
    {
        int x, c;
        cin >> x >> c;
        add.push_back({ x,c });
        alls.push_back(x);
    }
    int l, r;
    while (m--)
    {
        cin >> l >> r;
        quary.push_back({ l,r });
        alls.push_back(l);
        alls.push_back(r);
    }
    sort(alls.begin(), alls.end());
    alls.erase(unique(alls.begin(), alls.end()), alls.end());
    for (int i = 0; i < add.size(); i++)
    {
        PII item = add[i];
        int x = find(item.first);
        a[x] += item.second;
    }
    for (int i = 0; i <= N; i++)s[i] = s[i - 1] + a[i];
    for (int i = 0; i < quary.size(); i++)
    {
        PII item = quary[i];
        l = find(item.first);
        r = find(item.second);
        cout << s[r] - s[l - 1] << endl;
    }
}