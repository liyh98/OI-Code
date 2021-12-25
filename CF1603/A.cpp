#include <bits/stdc++.h>
using namespace std;

int gcd(int x, int y)
{
	return x ? gcd(y, x % y) : y;
}

inline void TC()
{
	int n;
	long long now = 1;
	scanf("%d", &n);
	bool flag = 1;
	for (int i = 1; i <= n; i++)
	{
		int x;
		scanf("%d", &x);
		if (now <= 1000000000)
			now *= (i + 1) / gcd(now, i + 1);
		if (x % now == 0)
			flag = 0;
	}
	puts(flag ? "YES" : "NO");
}

int main()
{
	int T;
	scanf("%d", &T);
	while (T--)
		TC();
	return 0;
}