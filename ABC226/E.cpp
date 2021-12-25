#include <bits/stdc++.h>
using namespace std;

vector<int> e[200001];
int flag;
int v[200001];
void dfs(int x, int pre = 0)
{
	v[x] = 1;
	for (int y : e[x])
	{
		if (y != pre && v[y] == 1)
			flag++;
		if (y != pre && !v[y])
			dfs(y, x);
	}
	v[x] = 2;
}
int main()
{
	int N, M;
	cin.tie(0);
	cin >> N >> M;
	while (M--)
	{
		int u, v;
		cin >> u >> v;
		e[u].push_back(v);
		e[v].push_back(u);
	}
	int ans = 1;
	for (int i = 1; i <= N; i++)
	{
		if (!v[i])
		{
			flag = 0;
			dfs(i);
			if (flag != 1)
			{
				cout << 0;
				return 0;
			}
			ans = (ans << 1) % 998244353;
		}
	}
	cout << ans << '\n';
	return 0;
}