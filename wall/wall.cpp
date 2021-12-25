#include "wall.h"
#include <bits/stdc++.h>
using namespace std;

int ma[10000000], mi[10000000];

void build(int x, int l, int r)
{
	mi[x] = 0;
	ma[x] = INT_MAX;
	if (l == r) return;
	int mid = (l + r) >> 1;
	build(x << 1, l, mid);
	build(x << 1 | 1, mid + 1, r);
}

void update(int x, int l, int r, int a, int b, int op, int val)
{
	if (l == a && r == b)
	{
		if (op)
			mi[x] = min(mi[x], val), ma[x] = min(ma[x], val);
		else
			mi[x] = max(mi[x], val), ma[x] = max(ma[x], val);
		return;
	}
	mi[x << 1] = min(max(mi[x << 1], mi[x]), ma[x]);
	ma[x << 1] = min(max(ma[x << 1], mi[x]), ma[x]);
	mi[x << 1 | 1] = min(max(mi[x << 1 | 1], mi[x]), ma[x]);
	ma[x << 1 | 1] = min(max(ma[x << 1 | 1], mi[x]), ma[x]);
	mi[x] = 0;
	ma[x] = INT_MAX;
	int mid = (l + r) >> 1;
	if (b <= mid)
		update(x << 1, l, mid, a, b, op, val);
	else if (a > mid)
		update(x << 1 | 1, mid + 1, r, a, b, op, val);
	else
		update(x << 1, l, mid, a, mid, op, val), update(x << 1 | 1, mid + 1, r, mid + 1, b, op, val);
}

int query(int x, int l, int r, int pos)
{
	if (l == r) return mi[x];
	mi[x << 1] = min(max(mi[x << 1], mi[x]), ma[x]);
	ma[x << 1] = min(max(ma[x << 1], mi[x]), ma[x]);
	mi[x << 1 | 1] = min(max(mi[x << 1 | 1], mi[x]), ma[x]);
	ma[x << 1 | 1] = min(max(ma[x << 1 | 1], mi[x]), ma[x]);
	mi[x] = 0;
	ma[x] = INT_MAX;
	int mid = (l + r) >> 1;
	if (pos <= mid) return query(x << 1, l, mid, pos);
	return query(x << 1 | 1, mid + 1, r, pos);
}

void buildWall(int n, int k, int op[], int left[], int right[], int height[], int finalHeight[])
{
	build(1, 0, n - 1);
	for (int i = 0; i < k; i++)
		update(1, 0, n - 1, left[i], right[i], op[i] - 1, height[i]);
	for (int i = 0; i < n; i++)
		finalHeight[i] = query(1, 0, n - 1, i);
}
