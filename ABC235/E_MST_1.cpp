#include <bits/stdc++.h>
using namespace std;

tuple<int, int, int, int> edges[400001];
bool ans[200001];

int fa[200001];

int find(int x)
{
    return x == fa[x] ? x : fa[x] = find(fa[x]);
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int n, m, q;
    cin >> n >> m >> q;
    for (int i = 1; i <= m; i++)
    {
        int u, v, w;
        cin >> u >> v >> w;
        edges[i] = make_tuple(w, u, v, 0);
    }
    for (int i = 1; i <= q; i++)
    {
        int u, v, w;
        cin >> u >> v >> w;
        edges[m + i] = make_tuple(w, u, v, i);
    }
    sort(edges + 1, edges + m + q + 1);
    for (int i = 1; i <= n; i++)
        fa[i] = i;
    for (int i = 1; i <= m + q; i++)
    {
        int u, v, w, id;
        tie(w, u, v, id) = edges[i];
        u = find(u);
        v = find(v);
        if (!id)
        {
            if (u != v)
                fa[u] = v;
        }
        else
        {
            ans[id] = u != v;
        }
    }
    for (int i = 1; i <= q; i++)
        puts(ans[i] ? "Yes" : "No");
    return 0;
}
