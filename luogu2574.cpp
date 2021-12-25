#include <bits/stdc++.h>
using namespace std;

char s[200001];
int tree[1000000];
bool tag[1000000];
#define ls (idx << 1)
#define rs (idx << 1 | 1)

void build(int idx, int l, int r)
{
    if (l == r)
    {
        tree[idx] = s[l] - '0';
        return;
    }
    int mid = (l + r) >> 1;
    build(ls, l, mid);
    build(rs, mid + 1, r);
    tree[idx] = tree[ls] + tree[rs];
}

int query(int idx, int l, int r, int x, int y)
{
    if (l == x && r == y) return tag[idx] ? r - l + 1 - tree[idx] : tree[idx];
    if (tag[idx])
    {
        tree[idx] = r - l + 1 - tree[idx];
        tag[ls] ^= 1;
        tag[rs] ^= 1;
        tag[idx] = 0;
    }
    int mid = (l + r) >> 1;
    if (y <= mid) return query(ls, l, mid, x, y);
    if (x > mid) return query(rs, mid + 1, r, x, y);
    return query(ls, l, mid, x, mid) + query(rs, mid + 1, r, mid + 1, y);
}

void update(int idx, int l, int r, int x, int y)
{
    if (l == x && r == y)
    {
        tag[idx] ^= 1;
        return;
    }
    tag[ls] ^= tag[idx];
    tag[rs] ^= tag[idx];
    tag[idx] = 0;
    int mid = (l + r) >> 1;
    if (y <= mid) update(ls, l, mid, x, y);
    else if (x > mid) update(rs, mid + 1, r, x, y);
    else update(ls, l, mid, x, mid), update(rs, mid + 1, r, mid + 1, y);
    tree[idx] = (tag[ls] ? mid - l + 1 - tree[ls] : tree[ls]) + (tag[rs] ? r - mid - tree[rs] : tree[rs]);
}

int main()
{
    int n, m;
    scanf("%d%d%s", &n, &m, s + 1);
    build(1, 1, n);
    while (m--)
    {
        int op, l, r;
        scanf("%d%d%d", &op, &l, &r);
        if (op) printf("%d\n", query(1, 1, n, l, r));
        else update(1, 1, n, l, r);
    }
    return 0;
}