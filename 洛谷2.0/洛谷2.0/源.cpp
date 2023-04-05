#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
#include <algorithm>
#include <cstring>

using namespace std;

int n;
struct Edge
{
	int head, tail, val;
}a[150005];

int f[150005];

bool cmp(Edge p1, Edge p2)
{
	return p1.tail < p2.tail;
}
//找到比当前头小的最小的区间左端点
int check(int l, int r, int key)
{
	int ans = 0;
	while (l < r)
	{
		int mid = l + r + 1 >> 1;
		if (a[mid].tail < key)
		{
			ans = mid;
			l = mid;
		}
		else r = mid - 1;
	}
	return ans;
}

int main()
{
	cin >> n;
	for (int i = 1; i <= n; i++)
	{
		cin >> a[i].head >> a[i].tail;
		a[i].val = a[i].tail - a[i].head + 1;
	}
	//按区间右端点排序
	sort(a + 1, a + n + 1, cmp);
	for (int i = 1; i <= n; i++)
	{
		//转移方程：f[i]=max(f[i-1],f[j]+a[i].tail-a[i].head+1)
		//1.f[i-1]表示可以不选
		//2.f[j]表示选当前区间时，区间左端点的最小位置，从f[j]转移到f[i]经过了a[i].tail-a[i].head+1
		f[i] = max(f[i - 1], f[check(1, i - 1, a[i].head)] + a[i].val);
	}
	cout << f[n];
}