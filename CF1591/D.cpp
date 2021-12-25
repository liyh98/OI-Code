#include <bits/stdc++.h>
using namespace std;

int n, tree[500001];

int get(int x)
{
	int ret = 0;
	for (; x <= n; x += x & -x)
		ret += tree[x];
	return ret;
}

void add(int x)
{
	for (; x; x -= x & -x)
		tree[x]++;
}

inline void TC()
{
	cin >> n;
	for (int i = 1; i <= n; i++)
		tree[i] = 0;
	bool flag = 0;
	long long sum = 0;
	for (int i = 1; i <= n; i++)
	{
		int x;
		cin >> x;
		int c = get(x), c1 = get(x + 1);
		if (c > c1)
			flag = 1;
		sum += c1;
		add(x);
	}
	puts(flag || !(sum & 1) ? "YES" : "NO");
}

int main()
{
	int t;
	cin.tie(0);
	cin >> t;
	while (t--)
		TC();
	return 0;
}