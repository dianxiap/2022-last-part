#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
#include <cstring>
using namespace std;

int main()
{
	int m, s, t;
	cin >> m >> s >> t;
	int s1 = 0, s2 = 0;
	for (int i = 1; i <= t; i++)
	{
		s1 += 17;
		if (m >= 10)
		{
			s2 += 60;
			m -= 10;
		}
		else m += 4;
		if (s2 > s1)s1 = s2;
		if (s1 >= s)
		{
			cout << "Yes" << endl;
			cout << i;
			return 0;;
		}
	}
	cout << "No" << endl << s1;
}