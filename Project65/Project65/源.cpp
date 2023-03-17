#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
#include <algorithm>
using namespace std;

const int N = 500010;
int n;
long double s;

int a[N];

int main()
{
	cin >> n >> s;
	for (int i = 1; i <= n; i++)cin >>a[i];
	sort(a, a + n);

	long double res = 0, avg = s / n;
	for (int i = 1; i <= n; i++)
	{
		double cur = s / (n - i + 1);
		if (a[i] < cur)cur = a[i];
		res += (cur - avg) * (cur - avg);
		s -= cur;
	}
	printf("%0.4lf", sqrt(res / n));
}