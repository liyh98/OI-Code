#include <bits/stdc++.h>
using namespace std;

int a[100001], ans;
bool v[100001];

void dfs(int x)
{
	v[x] = 1;
	ans++;
	if (!v[a[x]])
		dfs(a[x]);
}

int main()
{
	int n, x;
	cin.tie(0);
	cin >> n >> x;
	for (int i = 1; i <= n; i++)
		cin >> a[i];
	dfs(x);
	cout << ans;
	return 0;
}