#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
using namespace std;

const int N = 200010;

typedef long long LL;

int n, m;
LL cat1[N], cat2[N];
LL master1[N], master2[N];

int main()
{
	cin >> n >> m;
	for (int i = 1; i <= n; i++)
		cin >> cat1[i];
	for (int i = 1; i <= n; i++)
		cin >> cat2[i];
	for (int i = 1; i <= m; i++)
		cin >> master1[i];
	for (int i = 1; i <= m; i++)
		cin >> master2[i];

	LL res = 0;
	for (int i = 1; i <= m; i++)
	{
		for (int j = 1; j <= n; j++)
		{
			if (master1[i] >= cat2[j] && cat1[j] >= master2[i])
			{
				res = max(res, master1[i]);
			}
		}
	}

}