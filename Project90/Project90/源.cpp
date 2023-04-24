#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
using namespace std;

const int N = 200010;

int n,m;
char a[N];

int main()
{
	int t;
	cin >> t;
	while (t--)
	{
		cin >> n >> m;
		bool use = false;
		for (int i = 0; i < n; i++)cin >> a[i];
		for (int i = 0; i < n; i++)
		{
			int p = a[i] - '0';
			if (m > p && !use)
			{
				use = true;
				cout << m<<p;
			}
			else cout << p;
		}
		if (!use)cout << m;
		cout << endl;
	}
}