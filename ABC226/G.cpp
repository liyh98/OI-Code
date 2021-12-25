#include <bits/stdc++.h>
using namespace std;

long long a[6], b[6];

void take(int x, int y)
{
	long long t = min(b[x], a[y]);
	a[y] -= t;
	b[x] -= t;
	b[x - y] += t;
}

int main()
{
	int T;
	cin.tie(0);
	cin >> T;
	while (T--)
	{
		for (int i = 1; i <= 5; i++)
			cin >> a[i];
		for (int i = 1; i <= 5; i++)
			cin >> b[i];
		take(5, 5);
		take(4, 4);
		take(5, 4);
		take(3, 3);
		take(5, 3);
		take(4, 3);
		for (int i = 5; i >= 2; i--)
			take(i, 2);
		for (int i = 5; i >= 1; i--)
			take(i, 1);
		bool flag = 0;
		for (int i = 1; i <= 5; i++)
			flag |= a[i];
		puts(flag ? "No" : "Yes");
	}
}