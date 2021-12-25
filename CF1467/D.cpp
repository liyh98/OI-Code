#include <bits/stdc++.h>
using namespace std;

int c[5002][5001], a[5001];
long long tot[5001];
#define MOD 1000000007
int main()
{
	int n, k, q;
	scanf("%d%d%d", &n, &k, &q);
	for (int i = 1; i <= n; i++)
		c[i][0] = 1;
	for (int i = 1; i <= k; i++)
	{
		for (int j = 1; j <= n; j++)
			c[j][i] = (c[j - 1][i - 1] + c[j + 1][i - 1]) % MOD;
	}
	for (int i = 1; i <= n; i++)
	{
		for (int j = 0; j + j <= k; j++)
		{
			if (j + j == k)
				tot[i] = (tot[i] + (long long)c[i][j] * c[i][j] % MOD) % MOD;
			else
				tot[i] = (tot[i] + (long long)c[i][j] * c[i][k - j] % MOD * 2 % MOD) % MOD;
		}
	}
	long long ans = 0;
	for (int i = 1; i <= n; i++)
	{
		scanf("%d", &a[i]);
		ans = (ans + tot[i] * a[i] % MOD) % MOD;
	}
	while (q--)
	{
		int i, x;
		scanf("%d%d", &i, &x);
		ans = (ans + MOD + tot[i] * (x - a[i]) % MOD) % MOD;
		a[i] = x;
		printf("%lld\n", ans);
	}
	return 0;
}