#include <bits/stdc++.h>
using namespace std;

int x[501], y[501];
set<pair<int, int>> s;

int gcd(int x, int y)
{
	return x ? gcd(y % x, x) : y;
}

void add(int x, int y)
{
	if (x || y)
	{
		int g = gcd(abs(x), abs(y));
		s.emplace(x / g, y / g);
	}
}
int main()
{
	int n;
	cin.tie(0);
	cin >> n;
	for (int i = 1; i <= n; i++)
	{
		cin >> x[i] >> y[i];
		for (int j = 1; j < i; j++)
		{
			add(x[i] - x[j], y[i] - y[j]);
			add(x[j] - x[i], y[j] - y[i]);
		}
	}
	cout << s.size();
	return 0;
}