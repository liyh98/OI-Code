#include <bits/stdc++.h>
using namespace std;

#define MOD 998244353

int d[21][50001], c[21];
long long f[21], rf[21];

long long ksm(long long base, long long expo = MOD - 2)
{
	long long ret = 1;
	while (expo)
	{
		if (expo & 1)
			ret = (ret * base) % MOD;
		base = (base * base) % MOD;
		expo >>= 1;
	}
	return ret;
}

long long P(int n, int m)
{
	return f[n] * rf[n - m] % MOD;
}

int main()
{
	int n, m;
	scanf("%d%d", &n, &m);
	rf[0] = f[0] = 1;
	for (int i = 1; i <= n; i++)
		f[i] = (f[i - 1] * i) % MOD;
	rf[n] = ksm(f[n]);
	for (int i = n - 1; i; i--)
		rf[i] = (rf[i + 1] * (i + 1)) % MOD;
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= m; j++)
			scanf("%d", &d[i][j]);
	long long ans = 0;
	for (int i = 1; i <= m; i++)
	{
		memset(c, 0, sizeof c);
		for (int j = 1; j <= n; j++)
			c[d[j][i] - 1]++;
		int now = 1, s = 0;
		for (int j = 0; j <= n; j++)
		{
			if (s + c[j] > j)
			{
				now = 0;
				break;
			}
			now = (now * P(j - s, c[j])) % MOD;
			s += c[j];
		}
		ans = (ans + f[n] - now + MOD) % MOD;
	}
	ans = ans * rf[n] % MOD;
	printf("%lld", ans);
}