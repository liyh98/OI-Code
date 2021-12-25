#include <bits/stdc++.h>
using namespace std;

vector<int> edges[200001];
int ans, f[200001], fa[200001];

int find(int x)
{
	return x == fa[x] ? x : fa[x] = find(fa[x]);
}

inline void connect(int x, int y)
{
	x = find(x), y = find(y);
	if (x == y)
		return;
	ans--;
	fa[x] = y;
}

int main()
{
	int n, m;
	cin.tie(0);
	cin >> n >> m;
	while (m--)
	{
		int x, y;
		cin >> x >> y;
		if (x > y)
			swap(x, y);
		edges[x].push_back(y);
	}
	for (int i = n; i; i--)
	{
		f[i] = ans;
		fa[i] = i;
		ans++;
		for (int x : edges[i])
			connect(i, x);
	}
	cout.tie(0);
	for (int i = 1; i <= n; i++)
		cout << f[i] << '\n';
	return 0;
}