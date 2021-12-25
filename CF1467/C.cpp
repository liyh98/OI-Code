#include <bits/stdc++.h>
using namespace std;

inline void TC()
{
	int na, nb, nc, m1 = INT_MAX, m2 = INT_MAX, m3 = INT_MAX;
	long long tot = 0, mi = INT_MAX, subtot = 0;
	scanf("%d%d%d", &na, &nb, &nc);
	for (int i = 1; i <= na; i++)
	{
		int x;
		scanf("%d", &x);
		tot += x;
		subtot += x;
		m1 = min(m1, x);
	}
	mi = min(mi, subtot);
	subtot = 0;
	for (int i = 1; i <= nb; i++)
	{
		int x;
		scanf("%d", &x);
		tot += x;
		subtot += x;
		m2 = min(m2, x);
	}
	mi = min(mi, subtot);
	subtot = 0;
	for (int i = 1; i <= nc; i++)
	{
		int x;
		scanf("%d", &x);
		tot += x;
		subtot += x;
		m3 = min(m3, x);
	}
	mi = min(mi, subtot);
	mi = min(mi, (long long)m1 + min(m2, m3));
	mi = min(mi, (long long)m2 + m3);
	printf("%lld", tot - mi - mi);
}

int main()
{
	int T;
	//scanf("%d", &T);
	//while (T--)
	TC();
	return 0;
}