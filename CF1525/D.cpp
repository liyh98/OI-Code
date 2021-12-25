#include <bits/stdc++.h>
using namespace std;

int e[5001], f[5001], r[5001];
long long a[5001][5001];
int main()
{
	int n, m = 0, u = 0;
	scanf("%d", &n);
	for (int i = 1; i <= n; i++)
	{
		int x;
		scanf("%d", &x);
		if (x)
			f[++u] = i;
		else
			e[++m] = i;
	}
	for (int i = 1; i <= u; i++)
	{
		for (int j = 0; j <= m; j++)
		{
			a[i][j] = INT_MAX;
		}
	}
	for (int i = 1; i <= u; i++)
	{
		for (int j = 1; j <= m; j++)
		{
			a[i][j] = min(a[i][j], a[i][j - 1]);
			a[i][j] = min(a[i][j], a[i - 1][j - 1] + abs(f[i] - e[j]));
		}
	}
	printf("%lld", a[u][m]);
	return 0;
}