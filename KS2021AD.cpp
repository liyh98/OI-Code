#include <bits/stdc++.h>
using namespace std;

int b[1001][1001], f[1001], ans, N;
bool v[1001];

inline void prim(int x)
{
	if (v[x])
		return;
	memset(f, 0, sizeof f);
	while (true)
	{
		v[x] = 1;
		int nex = 0;
		for (int i = 1; i <= N + N; i++)
		{
			f[i] = max(f[i], b[x][i]);
			if (!v[i] && f[nex] < f[i])
				nex = i;
		}
		if (!nex)
			break;
		ans += f[nex];
		x = nex;
	}
}
inline void TC()
{
	int x, sum = 0;
	ans = 0;
	memset(v, 0, sizeof v);
	memset(b, 0, sizeof b);
	scanf("%d", &N);
	for (int i = 1; i <= N; i++)
		for (int j = 1; j <= N; j++)
			scanf("%d", &x);
	for (int i = 1; i <= N; i++)
		for (int j = 1; j <= N; j++)
		{
			scanf("%d", &b[i][j + N]);
			b[j + N][i] = b[i][j + N];
			sum += b[i][j + N];
		}
	for (int i = 1; i <= N; i++)
		scanf("%d%d", &x, &x);
	for (int i = 1; i <= N + N; i++)
		prim(i);
	printf("%d\n", sum - ans);
}
int main()
{
	int T;
	scanf("%d", &T);
	for (int i = 1; i <= T; i++)
	{
		printf("Case #%d: ", i);
		TC();
	}
	return 0;
}