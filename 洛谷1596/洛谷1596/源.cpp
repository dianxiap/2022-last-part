#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
#include <cstring>
#include <algorithm>
#include <queue>

using namespace std;
typedef pair<int, int> PII;
const int N = 310;

int sx, sy;
int fx, fy;
int n, m;
char a[N][N];
int f[N][N];
queue<PII> q;
int dx[4] = { 0,0,-1,1 };
int dy[4] = { -1,1,0,0 };

void change(int& xx, int& yy)
{
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++ )
		{
			if (a[xx][yy] == a[i][j])
			{
				xx = i;
				yy = j;
				return;
			}
		}
	}
}

void bfs(int x, int y)
{
	memset(f, -1, sizeof f);
	f[x][y] = 0;
	q.push({ x,y });
	while (q.size())
	{
		auto t = q.front();
		q.pop();
		for (int i = 0; i < 4; i++)
		{
			if (a[t.first][t.second] == '=')return;
			if (a[t.first][t.second] >= 'A' && a[t.first][t.second] <= 'Z')change(t.first, t.second);
			int xx = t.first + dx[i], yy = t.second + dy[i];
			if (xx >= 0 && xx < n && yy >= 0 && yy < m && a[xx][yy] != '#' && f[xx][yy] == -1)
			{
				f[xx][yy] = f[t.first][t.second] + 1;
				q.push({ xx,yy });
			}
		}

	}

}
int main()
{
	cin >> n >> m;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			cin >>a[i][j];
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
		{
			if (a[i][j] == '@')sx = i, sy = j;
			if (a[i][j] == '=')fx = i, fy = j;
		}
	bfs(sx, sy);
	cout << f[fx][fy];
}


