#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>

using namespace std;
typedef long long LL;
const int N = 100010;

int n, k;
LL a[N],cnt[N];

int main()
{
	cin >> n >> k;
	for (int i = 1; i <= n; i++)
	{
		cin >> a[i];
		a[i] += a[i - 1];
	}
	LL res = 0;

	cnt[0] = 1;
	for (int i = 1; i <= n; i++)
	{
		res+=cnt[a[i] % k];
		cnt[a[i] % k]++;
	}
	cout << res;
}
