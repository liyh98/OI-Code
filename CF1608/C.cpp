#include <bits/stdc++.h>
using namespace std;

pair<int, int> a[100001], b[100001];
int x[100001], y[100001], ma[100001], mb[100001];

inline void TC()
{
	int n;
	scanf("%d", &n);
	for (int i = 1; i <= n; i++)
		scanf("%d", &x[i]);
	for (int i = 1; i <= n; i++)
		scanf("%d", &y[i]);
	for (int i = 1; i <= n; i++)
	{
		a[i] = make_pair(x[i], y[i]);
		b[i] = make_pair(y[i], x[i]);
	}
	sort(a + 1, a + n + 1);
	sort(b + 1, b + n + 1);
	ma[n] = b[n].second;
	mb[n] = a[n].second;
	for (int i = n - 1; i; i--)
	{
		ma[i] = min(ma[i + 1], b[i].second);
		mb[i] = min(mb[i + 1], a[i].second);
	}
	// for (int i = 1; i <= n; i++)
	// cout << a[i].first << '\n';
	int ansa = a[n].first, ansb = b[n].first;
	while (1)
	{
		int ta = min(ansa, ma[lower_bound(b + 1, b + n + 1, make_pair(ansb, 0)) - b]);
		int tb = min(ansb, mb[lower_bound(a + 1, a + n + 1, make_pair(ansa, 0)) - a]);
		if (ta == ansa && tb == ansb)
			break;
		ansa = ta, ansb = tb;
	}
	for (int i = 1; i <= n; i++)
		putchar(x[i] >= ansa || y[i] >= ansb ? '1' : '0');
	putchar('\n');
}

int main()
{
	int T;
	scanf("%d", &T);
	while (T--)
		TC();
	return 0;
}