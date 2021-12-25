#include <bits/stdc++.h>
using namespace std;

int a[200001], b[200001], tree[800001], best[800001], opt[800001], opt_choice[800001], tag[800001];
pair<int, int> sb[200001];

void build(int node, int l, int r)
{
    opt[node] = INT_MAX;
    opt_choice[node] = l;
    if (l == r)
    {
        tree[node] = sb[l].first;
        best[node] = l;
        return;
    }
    int mid = (l + r) >> 1;
    build(node << 1, l, mid);
    build(node << 1 | 1, mid + 1, r);
    if (tree[node << 1] <= tree[node << 1 | 1])
    {
        tree[node] = tree[node << 1];
        best[node] = best[node << 1];
    }
    else
    {
        tree[node] = tree[node << 1 | 1];
        best[node] = best[node << 1 | 1];
    }
}
void update(int node, int l, int r, int x, int y, int val)
{
    if (l == r)
    {
        if (tag[node] > val)
        {
            tag[node] = val;
            if (opt[node] >)
        }
    }
}

void remove(int node, int l, int r, int x)
{
    if (l == r)
    {
        tree[node] = INT_MAX;
        return;
    }
    int mid = (l + r) >> 1;
    if (x <= mid)
        remove(node << 1, l, mid, x);
    else
        remove(node << 1 | 1, mid + 1, r, x);
    if (tree[node << 1] <= tree[node << 1 | 1])
    {
        tree[node] = tree[node << 1];
        best[node] = best[node << 1];
    }
    else
    {
        tree[node] = tree[node << 1 | 1];
        best[node] = best[node << 1 | 1];
    }
}

int get;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int n, m;
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
    }
    for (int i = 1; i <= n; i++)
    {
        cin >> b[i];
        sb[i] = make_pair(b[i], i);
    }
    sort(sb + 1, sb + n + 1);
    build(1, 1, n);
    long long ans = 0;
    for (int i = 1; i <= n; i++)
    {
        int x = get(1, 1, n);
        if (x == n)
        {
            ans = ggg;
            break;
        }
        int pos = lower_bound(sb + 1, sb + n + 1, make_pair(m - a[x], 0)) - sb;
        update(1, 1, n, 1, pos - 1, a[x]);
        update(1, 1, n, pos, n, a[x] - m);
        remove(1, 1, n, x);
    }
    cout << ans;
    return 0;
}
