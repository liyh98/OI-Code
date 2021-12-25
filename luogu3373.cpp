#include <bits/stdc++.h>
using namespace std;

int a[100001], p;
long long tree[1000000], add[1000000], mul[1000000];
#define ls (idx << 1)
#define rs (idx << 1 | 1)

void build(int idx, int l, int r)
{
    mul[idx] = 1;
    if (l == r)
    {
        tree[idx] = a[l] % p;
        return;
    }
    int mid = (l + r) >> 1;
    build(ls, l, mid);
    build(rs, mid + 1, r);
    tree[idx] = (tree[ls] + tree[rs]) % p;
}

int query(int idx, int l, int r, int x, int y)
{
    if (l == x && r == y) return (tree[idx] * mul[idx] + add[idx] * (r - l + 1)) % p;
    tree[idx] = (tree[idx] * mul[idx] + add[idx] * (r - l + 1)) % p;
    add[ls] = (add[ls] * mul[idx] + add[idx]) % p;
    mul[ls] = mul[ls] * mul[idx] % p;
    add[rs] = (add[rs] * mul[idx] + add[idx]) % p;
    mul[rs] = mul[rs] * mul[idx] % p;
    add[idx] = 0;
    mul[idx] = 1;
    int mid = (l + r) >> 1;
    if (y <= mid) return query(ls, l, mid, x, y);
    if (x > mid) return query(rs, mid + 1, r, x, y);
    return (query(ls, l, mid, x, mid) + query(rs, mid + 1, r, mid + 1, y)) % p;
}

void update(int idx, int l, int r, int x, int y, int m, int val)
{
    if (l == x && r == y)
    {
        if (m == 1) add[idx] = add[idx] * val % p, mul[idx] = mul[idx] * val % p;
        else (add[idx] += val) %= p;
        return;
    }
    add[ls] = (add[ls] * mul[idx] + add[idx]) % p;
    mul[ls] = mul[ls] * mul[idx] % p;
    add[rs] = (add[rs] * mul[idx] + add[idx]) % p;
    mul[rs] = mul[rs] * mul[idx] % p;
    add[idx] = 0;
    mul[idx] = 1;
    int mid = (l + r) >> 1;
    if (y <= mid) update(ls, l, mid, x, y, m, val);
    else if (x > mid) update(rs, mid + 1, r, x, y, m, val);
    else update(ls, l, mid, x, mid, m, val), update(rs, mid + 1, r, mid + 1, y, m, val);
    tree[idx] = (((tree[ls] * mul[ls] + add[ls] * (mid - l + 1)) % p) + ((tree[rs] * mul[rs] + add[rs] * (r - mid)) % p)) % p;
}

int main()
{
    int n, m;
    scanf("%d%d%d", &n, &m, &p);
    for (int i = 1; i <= n; i++) scanf("%d", &a[i]);
    build(1, 1, n);
    while (m--)
    {
        int op, l, r, x;
        scanf("%d%d%d", &op, &l, &r);
        if (op == 3) printf("%d\n", query(1, 1, n, l, r));
        else
        {
            scanf("%d", &x);
            update(1, 1, n, l, r, op, x % p);
        }
    }
    return 0;
}