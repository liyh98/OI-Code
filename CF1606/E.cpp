#include <bits/stdc++.h>
using namespace std;

#define MOD 998244353
inline long long kpow(long long base, long long expo)
{
	long long ret = 1;
	for (; expo; expo >>= 1, (base *= base) %= MOD)
		if (expo & 1)
			(ret *= base) %= MOD;
	return ret;
}

long long fac[501], inv[501], f[501][501];

inline long long C(int n, int m)
{
	return fac[n] * inv[m] % MOD * inv[n - m] % MOD;
}

bool v[501][501];
inline void TC()
{
	int n, x;
	scanf("%d %d", &n, &x);
	fac[0] = 1;
	for (int i = 1; i <= n; i++)
		fac[i] = (fac[i - 1] * i) % MOD;
	inv[n] = kpow(fac[n], MOD - 2) % MOD;
	for (int i = n - 1; i >= 0; i--)
		inv[i] = (inv[i + 1] * (i + 1)) % MOD;
	queue<pair<int, int>> q;
	q.emplace(n, x);
	v[n][x] = 1;
	while (!q.empty())
	{
		int i, j;
		tie(i, j) = q.front();
		q.pop();
		if (j >= i)
			for (int k = 0; k < i; k++)
				if (!v[i - k][j - i + 1])
				{
					v[i - k][j - i + 1] = 1;
					q.emplace(i - k, j - i + 1);
				}
	}
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= x; j++)
			if (v[i][j])
			{
				f[i][j] = kpow(min(i - 1, j), i);
				if (j >= i)
				{
					long long p = 1;
					for (int k = 0; k < i; k++, (p *= i - 1) %= MOD)
						(f[i][j] += C(i, k) * p % MOD * f[i - k][j - i + 1] % MOD) %= MOD;
				}
			}
	printf("%lld\n", f[n][x]);
}

int main()
{
	TC();
	return 0;
}