#include <bits/stdc++.h>
using namespace std;

int a[1000001], c[1000001], m, q[1000001], head, tail;
long long f[1000001];

inline double intersection(int x, int y)
{
	return (double)(f[x] - f[y]) / (c[x] - c[y]);
}

inline int read()
{
	int ret = 0;
	char c;
	for (c = getchar_unlocked(); c < '0' || c > '9'; c = getchar_unlocked())
		;
	for (; c >= '0' && c <= '9'; c = getchar_unlocked())
		ret = (ret << 3) + (ret << 1) + (c ^ '0');
	return ret;
}

int main()
{
	int n = read();
	for (int i = 1; i <= n; i++)
	{
		int x = read();
		if (x > a[m])
			a[++m] = x, c[m] = c[m - 1] + 1;
		else
			c[m]++;
	}
	for (int i = 1; i <= m; i++)
	{
		while (head < tail && intersection(q[head], q[head + 1]) < a[i])
			head++;
		f[i] = f[q[head]] + (long long)a[i] * (n - c[q[head]]);
		// printf("%d %d %lld\n", i, q[head], f[i]);
		while (head < tail && intersection(q[tail], i) < intersection(q[tail - 1], q[tail]))
			--tail;
		q[++tail] = i;
	}
	printf("%lld", f[m]);
	return 0;
}