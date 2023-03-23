#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
using namespace std;


const int N = 110;

int n;
char a[N][N];

void dfs(int x, int y)
{
	if (y == n)y = 0, x++;
	if (x == n)
	{
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < n; j++)
				cout << a[i][j];
			cout << endl;
		}
		return;
	}
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{

		}
	}
}

int main()
{
	cin >> n;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			cin >> a[i][j];
	dfs(0, 0);
}