#include <bits/stdc++.h>
using namespace std;

int a[1000001], cnt, rt[1000001], tree[20000000], ls[20000000], rs[20000000];

inline int read() {
    register char c = getchar_unlocked();
    int sign = 1, ret = 0;
    for (; c < '0' || c > '9'; c = getchar_unlocked()) if (c == '-') sign = -1;
    for (; c >= '0' && c <= '9'; c = getchar_unlocked()) (ret *= 10) += c ^ 48;
    return ret * sign;
}

void build(int &idx, int l, int r)
{
    idx = ++cnt;
    if (l == r) {
        tree[idx] = read();
        return;
    }
    int mid = (l + r) >> 1;
    build(ls[idx], l, mid);
    build(rs[idx], mid + 1, r);
}

void modify(int &idx, int pre, int l, int r, int loc, int val) {
    idx = ++cnt;
    if (l == r) {
        tree[idx] = val;
        return;
    }
    int mid = (l + r) >> 1;
    if (loc <= mid) rs[idx] = rs[pre], modify(ls[idx], ls[pre], l, mid, loc, val);
    else ls[idx] = ls[pre], modify(rs[idx], rs[pre], mid + 1, r, loc, val);
}

int query(int idx, int l, int r, int loc)
{
    if (l == r) return tree[idx];
    int mid = (l + r) >> 1;
    if (loc <= mid) return query(ls[idx], l, mid, loc);
    return query(rs[idx], mid + 1, r, loc);
}

int main() {
    int n = read(), m = read();
    build(rt[0], 1, n);
    for (register int i = 1; i <= m; i++) {
        int v = read(), op = read(), loc = read();
        if (op == 1) modify(rt[i], rt[v], 1, n, loc, read());
        else rt[i] = rt[v], printf("%d\n", query(rt[v], 1, n, loc));
    }
    return 0;
}