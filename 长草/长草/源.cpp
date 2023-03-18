#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
#include <cstring>
#include <queue>

using namespace std;

typedef pair<int, int> PII;
const int N = 1010;

int n, m,k;
char g[N][N];
queue<PII> q;

void bfs()
{
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			if (g[i][j] == 'g')
			{
				q.push({ i,j });
			}
		}
	}
	while (k--)
	{
		//在遍历过程中队列长度是不断边长的，但我们要一个月一个月的遍历，因此要先把每个月已经存在的长度存下来
		int cnt = q.size();  
		while (cnt--)
		{
			auto t = q.front();
			q.pop();
			int dx[4] = { 0,0,1,-1 };
			int dy[4] = { 1,-1,0,0 };
			for (int i = 0; i < 4; i++)
			{
				int x = t.first + dx[i], y = t.second + dy[i];
				if (x >= 0 && x < n && y >= 0 && y < m && g[x][y] == '.')
				{
					g[x][y] = 'g';
					q.push({ x,y });
					
				}
			}
		}
	}
}

int main()
{
	cin >> n >> m;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			cin >> g[i][j];
		}
	}
	cin >> k;	
	bfs();
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			cout << g[i][j];
		}
		cout << endl;
	}
}