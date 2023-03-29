#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
#include <algorithm>
using namespace std;

string s;
string p;

int main()
{
	cin >> s >> p;
	int res = 0;
	for (int i = 0; i < s.size(); i++)
	{
		if (s[i] != p[i])
		{
			if (s[i] == '*')s[i] = 'o';
			else s[i] = '*';
			if (s[i + 1] == '*')s[i + 1] = 'o';
			else s[i] = '*';
			res++;
		}
	}
	cout << res;
}