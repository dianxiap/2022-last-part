#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;

const int N = 20;

int n, k;
int a[N];
bool st[N];
int ans;
int res;

bool prime(int x)
{
	if (x < 2)return 0;
	for (int i = 2; i < x / i; i++)
	{
		if (x % i == 0)return 0;
	}
	return 1;
}

//从i开始选，sum为目前为止所有数的和，u为选的数的个数
void dfs(int i,int sum,int u)
{
	if (u == k)
	{
		if(prime(sum))
			res++;
		return;
	}
	else if(i<n)
	{
		dfs(i + 1, sum, u);
		dfs(i + 1, sum + a[i], u + 1);
	}
}

int main()
{
	cin >> n >> k;
	for (int i = 0; i < n; i++)cin >> a[i];
	dfs(0,0,0);
	cout << res;
}