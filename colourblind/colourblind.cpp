#include <bits/stdc++.h>
using namespace std;

vector<pair<long long, long long>> m;
int fa[500000];
long long c[500000][3][2];
vector<tuple<long long, int, int>> e;

int find(int x)
{
	return x == fa[x] ? x : fa[x] = find(fa[x]);
}

long long max(long long a, long long b, long long c)
{
	return max(a, max(b, c));
}

void init(int H, int W, int Q, int S, vector<vector<long long>> R, vector<vector<long long>> G, vector<vector<long long>> B)
{
	int num = 0;
	for (int i = 0; i < H; i++)
	{
		for (int j = 0; j < W; j++)
		{
			++num;
			fa[num] = num;
			c[num][0][0] = c[num][0][1] = R[i][j];
			c[num][1][0] = c[num][1][1] = G[i][j];
			c[num][2][0] = c[num][2][1] = B[i][j];
			if (j < W - 1)
				e.emplace_back(max(abs(R[i][j] - R[i][j + 1]), abs(G[i][j] - G[i][j + 1]), abs(B[i][j] - B[i][j + 1])), num, num + 1);
			if (i < H - 1)
				e.emplace_back(max(abs(R[i][j] - R[i + 1][j]), abs(G[i][j] - G[i + 1][j]), abs(B[i][j] - B[i + 1][j])), num, num + W);
		}
	}
	sort(e.begin(), e.end());
	int n = e.size();
	long long ans = 0;
	for (int i = 0; i < n; i++)
	{
		long long l;
		int x, y;
		tie(l, x, y) = e[i];
		x = find(x), y = find(y);
		if (x != y)
		{
			for (int i = 0; i < 3; i++)
			{
				c[x][i][0] = min(c[x][i][0], c[y][i][0]);
				c[x][i][1] = max(c[x][i][1], c[y][i][1]);
				ans = max(ans, c[x][i][1] - c[x][i][0]);
			}
			fa[y] = x;
		}
		if (i == n - 1 || l != get<0>(e[i + 1]))
			m.emplace_back(l, ans);
	}
	sort(m.begin(), m.end());
}

bool query(long long C)
{
	auto it = upper_bound(m.begin(), m.end(), make_pair(C, LLONG_MAX));
	return it != m.begin() && (--it)->second > C;
}
