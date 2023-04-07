#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
using namespace std;

int p_to_ten(string s, int p)
{
	int x = 0;
	for (int i = 0; i < s.size(); i++)
	{
		x *= p;
		if (s[i] >= 'A' && s[i] <= 'Z')x += (s[i] - 'A' + 10);
		else x += (s[i] - '0');
	}
	return x;
}

string ten_to_p(int x, int p)
{
	string res;
	int tmp = 0;
	do {
		tmp = x % p;
		if (tmp < 10)res.push_back('0' + tmp);
		else res.push_back('A' + tmp - 10);
		x /= p;
	} while (x);
	return res;
}

int main()
{

}