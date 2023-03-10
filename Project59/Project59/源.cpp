#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
using namespace std;

const int N = 110;

int a[N][N];
int b[N][N];
int n, m;

int main()
{
	cin >> n >> m;
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= m; j++)
			cin >> a[i][j];
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= m; j++)
		{
			if (a[i][j] == 1)b[i][j] =9;
			else
			{
				if (a[i - 1][j - 1] == 1)b[i][j]++;
				if (a[i - 1][j] == 1)b[i][j]++;
				if (a[i - 1][j + 1] == 1)b[i][j]++;
				if (a[i][j - 1] == 1)b[i][j]++;
				if (a[i][j + 1] == 1)b[i][j]++;
				if (a[i + 1][j - 1] == 1)b[i][j]++;
				if (a[i + 1][j] == 1)b[i][j]++;
				if (a[i + 1][j + 1] == 1)b[i][j]++;
			}
		}
	}

	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= m; j++)
		{
			cout << b[i][j] << ' ';
		}
		cout << endl;
	}
}
