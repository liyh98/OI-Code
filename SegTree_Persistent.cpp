#include <bits/stdc++.h>
using namespace std;

int k, n;
vector<pair<int, int>> e[100001];

int tree[5000001], ls[5000001], rs[5000001], rt[1000001], cnt;
int d[100001], fa[100001][17];
int h[1000001];

void update(int &x, int pre, int l, int r, int pos)
{
    x = ++cnt;
    tree[x] = tree[pre] + 1;
    if (l == r)
        return;
    int mid = (l + r) >> 1;
    if (pos <= mid)
        rs[x] = rs[pre], update(ls[x], ls[pre], l, mid, pos);
    else
        ls[x] = ls[pre], update(rs[x], rs[pre], mid + 1, r, pos);
}

void dfs(int x, int pre)
{
    for (int i = 1; (1 << i) <= d[x]; i++)
        fa[x][i] = fa[fa[x][i - 1]][i - 1];
    for (auto p : e[x])
    {
        int nex = p.first;
        if (nex == pre)
            continue;
        d[nex] = d[x] + 1;
        fa[nex][0] = x;
        update(rt[nex], rt[x], 0, n - 1, lower_bound(h + 1, h + n, p.second) - h);
        dfs(nex, x);
    }
}

inline int lca(int x, int y)
{
    if (d[x] < d[y])
        swap(x, y);
    int delta = d[x] - d[y];
    for (int i = 0; i < 17; i++)
        if ((1 << i) & delta)
            x = fa[x][i];
    if (x == y)
        return x;
    for (int i = 16; i >= 0; i--)
    {
        if (fa[x][i] != fa[y][i])
            x = fa[x][i], y = fa[y][i];
    }
    return fa[x][0];
}

int get(int fa, int x, int y, int l, int r, int tar)
{
    if (l == r)
        return l;
    int mid = (l + r) >> 1, left = tree[ls[x]] + tree[ls[y]] - (tree[ls[fa]] << 1), right = tree[rs[x]] + tree[rs[y]] - (tree[rs[fa]] << 1);
    //printf("%d %d %d\n", mid, left, right);
    //printf("%d %d %d %d %d %d\n", ls[x], ls[y], ls[fa], tree[ls[x]], tree[ls[y]], tree[ls[fa]]);
    if (tar <= left || !right)
        return get(ls[fa], ls[x], ls[y], l, mid, tar);
    return get(rs[fa], rs[x], rs[y], mid + 1, r, tar - left);
}

inline int query(int x, int y)
{
    int fa = lca(x, y);
    //printf("%d %d %d\n", fa, x, y);
    return h[get(rt[fa], rt[x], rt[y], 0, n - 1, k)];
}

inline int read()
{
    int ret = 0;
    char c = getchar_unlocked();
    for (; c < '0' || c > '9'; c = getchar_unlocked())
        ;
    for (; c >= '0' && c <= '9'; c = getchar_unlocked())
        (ret *= 10) += c ^ 48;
    return ret;
}

int pr[15];
inline void put(int x)
{
    if (x == -1)
        puts("-1");
    else
    {
        int len = 0;
        while (x)
            pr[++len] = x % 10, x /= 10;
        while (len)
            putchar_unlocked(pr[len--] ^ 48);
        putchar_unlocked('\n');
    }
}

int main()
{
    int q;
    n = read(), k = read(), q = read();
    for (int i = 1; i < n; i++)
    {
        int a = read() + 1, b = read() + 1, c = read();
        h[i] = c;
        e[a].emplace_back(b, c);
        e[b].emplace_back(a, c);
    }
    h[0] = -1;
    sort(h + 1, h + n);
    dfs(1, 0);
    int ans = 1;
    while (q--)
    {
        int x = read(), y = read();
        if (ans == -1)
            ans = n - 1;
        x = (x + ans) % n + 1, y = (y + ans) % n + 1;
        printf("%d\n", ans = query(x, y));
    }
    return 0;
}