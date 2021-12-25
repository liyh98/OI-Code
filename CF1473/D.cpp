#include <bits/stdc++.h>
using namespace std;

char p[200001];
int s[200001], f1[200001], f2[200001], b1[200002], b2[200002];

inline void TC()
{
	int n, m;
	scanf("%d%d%s", &n, &m, p + 1);
	for (int i = 1; i <= n; i++)
	{
		s[i] = s[i - 1] + (p[i] == '+' ? 1 : -1);
		f1[i] = max(f1[i - 1], s[i]);
		f2[i] = min(f2[i - 1], s[i]);
	}
	b1[n + 1] = s[n];
	b2[n + 1] = s[n];
	for (int i = n; i; i--)
	{
		b1[i] = max(b1[i + 1], s[i]);
		b2[i] = min(b2[i + 1], s[i]);
	}
	while (m--)
	{
		int l, r;
		scanf("%d%d", &l, &r);
		int ma = f1[l - 1], mi = f2[l - 1];
		//printf("%d %d\n", ma, mi);
		ma = max(ma, b1[r + 1] - s[r] + s[l - 1]);
		mi = min(mi, b2[r + 1] - s[r] + s[l - 1]);
		//printf("%d %d\n", ma, mi);
		printf("%d\n", ma - mi + 1);
	}
}

int main()
{
	int T;
	scanf("%d", &T);
	while (T--)
		TC();
	return 0;
}