#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>

using namespace std;

const int N = 210,mod=1000000007;

int n, m;
int f[N][N][N];

int main()
{
	cin >> n >> m;
	f[0][0][2] = 1;
	for (int i = 0; i <= n; i++)
	{
		for (int j = 0; j <= m-1 ;j++)
		{
			if (i == 0 && j == 0)continue;
			for (int k = 1; k <= 100; k++)
			{
				if (k % 2 == 0 && i)f[i][j][k] += f[i - 1][j][k / 2];
				if (j)f[i][j][k] += f[i][j - 1][k + 1];
				f[i][j][k] %= mod;
			}
		}
	}
	cout << f[n][m - 1][1];
}