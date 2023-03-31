#define _CRT_SECURE_NO_WARNINGS 1
#include <cstring>
#include <iostream>
#include <algorithm>

typedef long long LL;
using namespace std;

const int N = 100010, M = 2 * N;
int h[N], e[M], ne[M], idx, w[N];
int n;
LL f[N];

void add(int a, int  b)
{
	e[idx] = b, ne[idx] = h[a], h[a] = idx++;
}

//u为当前节点，f为父节点
void dfs(int u, int f)
{
	f[u] = w[u];
	for (int i = h[u]; i != -1; i = ne[i])
	{
		int j = e[i];
		if (j != f)
		{
			dfs(j, u);
			f[u] += max(0, f[j]);
		}
	}
}
int main()
{
	cin >> n;
	memset(h, -1, sizeof h);
	for (int i = 1; i <= n; i++)cin >> w[i];
	for (int i = 0; i < n - 1; i++)
	{
		int a, b;
		cin >> a >> b;
		add(a, b), add(b, a);
	}
	dfs(1, -1);
	LL res = f[1];
	for (int i = 2; i <= n; i++)res = max(res, f[i]);
	cout << res;
}