#include <bits/stdc++.h>
using namespace std;

#define MOD 998244353

int ans;
long long p[51], fac[51], inv[51], facinv[51];

long long qpow(long long base, long long expo)
{
	long long ret = 1;
	for (; expo; expo >>= 1, (base *= base) %= MOD)
		if (expo & 1)
			(ret *= base) %= MOD;
	return ret;
}

long long C(int n, int m)
{
	return fac[n] * facinv[m] % MOD * facinv[n - m] % MOD;
}
void dfs(int x, int s, long long now = 1, long long cyc = 1)
{
	if (!s)
	{
		ans = (ans + now) % MOD;
		return;
	}
	if (s < x)
		return;
	int g = gcd(cyc, x);
	dfs(x + 1, s, now, cyc);
	now = now * p[x / g] % MOD;
	cyc = cyc * x / g;
	for (int i = 1; s >= x; i++)
	{
		now = now * C(s, x) % MOD * fac[x - 1] % MOD * inv[i] % MOD;
		s -= x;
		dfs(x + 1, s, now, cyc);
	}
}
int main()
{
	int n, k;
	cin.tie(0);
	cin >> n >> k;
	facinv[0] = inv[1] = fac[0] = 1;
	for (int i = 1; i <= n; i++)
	{
		p[i] = qpow(i, k);
		fac[i] = fac[i - 1] * i % MOD;
		if (i > 1)
			inv[i] = (MOD - MOD / i * inv[MOD % i] % MOD) % MOD;
		facinv[i] = facinv[i - 1] * inv[i] % MOD;
	}
	dfs(1, n);
	cout << ans;
	return 0;
}