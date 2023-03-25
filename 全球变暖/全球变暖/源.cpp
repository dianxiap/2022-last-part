#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
#include <cstring>
using namespace std;

int k;
string str;

int dfs()
{
	int res = 0;
	while (k < str.size())
	{
		if (str[k] == '(')
		{
			k++;  //跳过 '('
			res += dfs();
			k++;  //跳过 ')'
		}
		else if (str[k] == '|')
		{
			k++;  //跳过 '|'
			res = max(res, dfs());
		}
		else if (str[k] == ')')break;
		else
		{
			k++;  //跳过 'x'
			res++;
		}
	}
	return res;
}
int main()
{
	cin >> str;
	cout << dfs() << endl;
}