#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
#include <cmath>
using namespace std;

const int N = 35;
int n, m;
int f[N][N];

int main()
{
	cin >> n >> m;
	f[1][1] = 1;
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= m; j++)
		{
			if(i%1==1||j%1==1)
			f[i][j] = f[i - 1][j] +f[i][j-1];
			
		}
	}
	cout << f[n][m];
}