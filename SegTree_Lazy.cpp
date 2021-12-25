#include <bits/stdc++.h>
using namespace std;

long long tree[800001], tag[800001];
int a[100001];

void update(int rt, int l, int r, int x, int val)
{
    if (l == r)
    {
        tree[rt] += val;
        return;
    }
    int mid = (l + r) >> 1;
    if (x <= mid)
        update(rt << 1, l, mid, x, val);
    else
        update(rt << 1 | 1, mid + 1, r, x, val);
    tree[rt] = tree[rt << 1] + tree[rt << 1 | 1];
}

void build(int rt, int l, int r)
{
    if (l == r)
    {
        tree[rt] = a[l];
        return;
    }
    int mid = (l + r) >> 1;
    build(rt << 1, l, mid);
    build(rt << 1 | 1, mid + 1, r);
    tree[rt] = tree[rt << 1] + tree[rt << 1 | 1];
}

void update(int rt, int l, int r, int x, int y, int val)
{
    if (l == x && r == y)
    {
        tag[rt] += val;
        return;
    }
    tag[rt << 1] += tag[rt];
    tag[rt << 1 | 1] += tag[rt];
    tag[rt] = 0;
    int mid = (l + r) >> 1;
    if (y <= mid)
        update(rt << 1, l, mid, x, y, val);
    else if (x > mid)
        update(rt << 1 | 1, mid + 1, r, x, y, val);
    else
        update(rt << 1, l, mid, x, mid, val), update(rt << 1 | 1, mid + 1, r, mid + 1, y, val);
    tree[rt] = tree[rt << 1] + tag[rt << 1] * (mid - l + 1) + tree[rt << 1 | 1] + tag[rt << 1 | 1] * (r - mid);
}

long long get(int rt, int l, int r, int x, int y)
{
    if (l == x && r == y)
        return tree[rt] + tag[rt] * (r - l + 1);
    tree[rt] += tag[rt] * (r - l + 1);
    tag[rt << 1] += tag[rt];
    tag[rt << 1 | 1] += tag[rt];
    tag[rt] = 0;
    int mid = (l + r) >> 1;
    if (y <= mid)
        return get(rt << 1, l, mid, x, y);
    if (x > mid)
        return get(rt << 1 | 1, mid + 1, r, x, y);
    return get(rt << 1, l, mid, x, mid) + get(rt << 1 | 1, mid + 1, r, mid + 1, y);
}

int main()
{
    int n, m;
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; i++)
        scanf("%d", &a[i]);
    build(1, 1, n);
    while (m--)
    {
        int op, x, y, k;
        scanf("%d%d%d", &op, &x, &y);
        if (op == 1)
        {
            scanf("%d", &k);
            update(1, 1, n, x, y, k);
        }
        else
            printf("%lld\n", get(1, 1, n, x, y));
    }
    return 0;
}