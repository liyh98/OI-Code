#include <bits/stdc++.h>
using namespace std;

vector<int> e[200001];
int t[200001];
bool v[200001];
int main()
{
	int n;
	cin.tie(0);
	cin >> n;
	for (int i = 1; i <= n; i++)
	{
		cin >> t[i];
		int k;
		cin >> k;
		while (k--)
		{
			int x;
			cin >> x;
			e[i].push_back(x);
		}
	}
	queue<int> q;
	q.push(n);
	v[n] = 1;
	long long ans = 0;
	while (!q.empty())
	{
		int x = q.front();
		q.pop();
		ans += t[x];
		for (int y : e[x])
		{
			if (!v[y])
			{
				v[y] = 1;
				q.push(y);
			}
		}
	}
	cout << ans;
	return 0;
}