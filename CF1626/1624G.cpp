#include <bits/stdc++.h>
using namespace std;

int fa[200001], sz[200001];

int find(int x)
{
    return x == fa[x] ? x : fa[x] = find(fa[x]);
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int T;
    cin >> T;
    while (T--)
    {
        int n, m;
        cin >> n >> m;
        vector<tuple<int, int, int>> edges(m);
        for (auto &[u, v, w] : edges)
            cin >> u >> v >> w;
        int ans = 0;
        for (int b = 29; b >= 0; b--)
        {
            for (int i = 1; i <= n; i++)
                fa[i] = i, sz[i] = 1;
            int now = ans | (1 << b), cnt = n - 1;
            for (auto [u, v, w] : edges)
            {
                if (!(now & w))
                {
                    u = find(u);
                    v = find(v);
                    if (u != v)
                    {
                        if (sz[u] > sz[v])
                            fa[v] = u, sz[v] += sz[u];
                        else
                            fa[u] = v, sz[u] += sz[v];
                        cnt--;
                    }
                }
            }
            if (!cnt)
                ans = now;
        }
        ans ^= (1 << 30) - 1;
        cout << ans << '\n';
    }
    return 0;
}
