
#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
#include <algorithm>
#include <cstring>
#include <queue>
using namespace std;

typedef pair<int, int> PII;;
const int N = 12;

int n;
int t[N];
int s[N];
int res=114514;

void dfs(int u, int l, int r)
{
	if (u == n)
	{
		if (l == 1 && r == 0)return;
		res = min(res, abs(l - r));
		return;
	}
	dfs(u + 1, l * t[u], r + s[u]);
	dfs(u + 1, l, r);
}

int main()
{
	cin >> n;
	for (int i = 0; i < n; i++)cin >> t[i] >> s[i];
	dfs(0, 1, 0);
	cout << res;
}

