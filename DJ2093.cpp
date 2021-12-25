#include <bits/stdc++.h>
using namespace std;

typedef pair<long long, int> pli;
vector<pair<int, int>> e[300000];
int in[300000], out[300000], T, re[300001];
pli tree[3000000];
long long tag[3000000], h[300000];
const long long inf = 300000000000ll;
bool oc[300000];

void build(int x, int l, int r)
{
	if (l == r)
	{
		tree[x] = make_pair(h[re[l]], re[l]);
		return;
	}
	int mid = (l + r) >> 1;
	build(x << 1, l, mid);
	build(x << 1 | 1, mid + 1, r);
	tree[x] = max(tree[x << 1], tree[x << 1 | 1]);
}

inline pli operator+(pli a, long long b)
{
	return make_pair(a.first + b, a.second);
}

pli query(int x, int l, int r, int a, int b)
{
	if (l == a && r == b)
		return tree[x] + tag[x];
	int mid = (l + r) >> 1;
	if (b <= mid)
		return query(x << 1, l, mid, a, b) + tag[x];
	if (a > mid)
		return query(x << 1 | 1, mid + 1, r, a, b) + tag[x];
	return max(query(x << 1, l, mid, a, mid), query(x << 1 | 1, mid + 1, r, mid + 1, b)) + tag[x];
}

void modify(int x, int l, int r, int a, int b, long long val)
{
	if (l == a && r == b)
	{
		tag[x] += val;
		return;
	}
	tag[x << 1] += tag[x];
	tag[x << 1 | 1] += tag[x];
	tag[x] = 0;
	int mid = (l + r) >> 1;
	if (b <= mid)
		modify(x << 1, l, mid, a, b, val);
	else if (a > mid)
		modify(x << 1 | 1, mid + 1, r, a, b, val);
	else
		modify(x << 1, l, mid, a, mid, val), modify(x << 1 | 1, mid + 1, r, mid + 1, b, val);
	tree[x] = max(tree[x << 1] + tag[x << 1], tree[x << 1 | 1] + tag[x << 1 | 1]);
}

void dfs(int x, int pre)
{
	in[x] = ++T;
	re[T] = x;
	for (auto p : e[x])
	{
		if (p.first == pre)
			continue;
		h[p.first] = h[x] + p.second;
		dfs(p.first, x);
	}
	out[x] = T;
}

int main()
{
	int n, q;
	scanf("%d%d", &n, &q);
	for (int i = 1; i < n; i++)
	{
		int a, b, l;
		scanf("%d%d%d", &a, &b, &l);
		e[a].emplace_back(b, l);
		e[b].emplace_back(a, l);
	}
	dfs(0, -1);
	build(1, 1, T);
	while (q--)
	{
		int op, x;
		scanf("%d%d", &op, &x);
		if (op == 1)
		{
			pli ma = query(1, 1, T, in[x], out[x]), hx = query(1, 1, T, in[x], in[x]);
			if (ma.first >= hx.first && !oc[ma.second])
			{
				oc[ma.second] = 1;
				modify(1, 1, T, in[ma.second], out[ma.second], -inf);
				printf("%d\n", ma.second);
			}
			else puts("-1");
		}
		else
			oc[x] = 0, modify(1, 1, T, in[x], out[x], inf);
	}
	return 0;
}