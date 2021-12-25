#include <bits/stdc++.h>
using namespace std;

vector<int> e[1000000];
int s[1000000], in[1000000], out[1000000], T, n, lst;
long long tree[1000001];

void update(int x, int val)
{
    for (; x <= n; x += x & -x)
        tree[x] += val;
}

long long query(int x)
{
    long long ret = 0;
    for (; x; x -= x & -x)
        ret += tree[x];
    return ret;
}

void dfs(int x)
{
    in[x] = ++T;
    update(T, s[x] - lst);
    lst = s[x];
    for (int nex : e[x])
            dfs(nex);
    out[x] = T;
}

int main()
{
    int q, p;
    scanf("%d%d", &n, &q);
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &p);
        if (i)
            e[p].push_back(i);
    }
    for (int i = 0; i < n; i++)
        scanf("%d", &s[i]);
    dfs(0);
    while (q--)
    {
        int d, x, s;
        scanf("%d%d", &d, &x);
        if (d) printf("%lld\n", query(in[x]));
        else
        {
            scanf("%d", &s);
            update(in[x], s);
            update(out[x] + 1, -s);
        }
    }
    return 0;
}