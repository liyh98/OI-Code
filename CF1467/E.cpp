#include <bits/stdc++.h>
using namespace std;

vector<int> e[200001], la[200001];
int ans, in[200001], out[200001], T, m, c[200001];
unordered_map<int, int> h;

bool flag;

void dfs(int x, int pre)
{
	in[x] = ++T;
	for (int nex : e[x])
	{
		if (nex != pre)
			dfs(nex, x);
	}
	out[x] = T;
}

int main()
{
	int n;
	scanf("%d", &n);
	for (int i = 1; i <= n; i++)
	{
		int x;
		scanf("%d", &x);
		if (!h.count(x))
			h[x] = ++m;
		la[h[x]].push_back(i);
	}
	for (int i = 1; i < n; i++)
	{
		int u, v;
		scanf("%d%d", &u, &v);
		e[u].push_back(v);
		e[v].push_back(u);
	}
	dfs(1, 0);
	for (int i = 1; i <= m; i++)
	{
		if (la[i].size() == 1)
			continue;
		set<int> s;
		s.clear();
		for (int x : la[i])
			s.insert(in[x]);
		for (int x : la[i])
		{
			c[in[x]]++;
			c[in[x] + 1]--;
			int cnt = 0;
			if (s.lower_bound(in[x]) == s.begin() && s.lower_bound(out[x] + 1) == s.end())
				c[1]++, c[in[x]]--, c[out[x] + 1]++;
			else
				cnt++;
			for (int nex : e[x])
			{
				if (in[nex] > in[x])
				{
					auto it = s.lower_bound(in[nex]);
					if (it == s.end() || *it > out[nex])
						c[in[nex]]++, c[out[nex] + 1]--;
					else
						cnt++;
				}
			}
			if (cnt > 1)
			{
				puts("0");
				return 0;
			}
		}
	}
	int now = 0;
	for (int i = 1; i <= T; i++)
	{
		//printf("%d\n", c[i]);
		now += c[i];
		if (!now)
			ans++;
	}
	printf("%d", ans);
	return 0;
}