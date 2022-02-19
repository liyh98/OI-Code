#include <bits/stdc++.h>
using namespace std;

int fa[51];

int find(int x)
{
    return x == fa[x] ? x : fa[x] = find(fa[x]);
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int n, m;
    cin >> n >> m;
    vector<array<int, 3>> edges(m);
    vector<int> Q;
    Q.push_back(99999999);
    for (auto &[w, u, v] : edges)
    {
        cin >> u >> v >> w;
        Q.push_back(w);
    }
    sort(edges.begin(), edges.end());
    for (int i = 0; i < m; ++i)
        for (int j = i + 1; j < m; ++j)
        {
            int mid = (edges[i][0] + edges[j][0]) >> 1;
            Q.push_back(mid);
            if (~(edges[i][0] ^ edges[j][0]) & 1)
                Q.push_back(mid - 1);
        }
    sort(Q.begin(), Q.end());
    auto it = unique(Q.begin(), Q.end());
    Q.erase(it, Q.end());
    int now = 0;
    vector<array<long long, 2>> ans(Q.size());
    for (int i = 0; i < Q.size(); ++i)
    {
        int q = Q[i];
        while (now < m && edges[now][0] < q)
            ++now;
        int f = now, b = now - 1;
        long long t = 0;
        for (int i = 1; i <= n; ++i)
            fa[i] = i;
        for (int j = 1; j < n; ++j)
        {
            while (1)
            {
                if (b < 0 || (f < m && edges[f][0] + edges[b][0] <= q << 1))
                {
                    auto [w, u, v] = edges[f++];
                    u = find(u), v = find(v);
                    if (u != v)
                    {
                        fa[u] = v;
                        ans[i][0] += w;
                        ans[i][1]--;
                        break;
                    }
                }
                else
                {
                    auto [w, u, v] = edges[b--];
                    u = find(u), v = find(v);
                    if (u != v)
                    {
                        fa[u] = v;
                        ans[i][0] -= w;
                        ans[i][1]++;
                        break;
                    }
                }
            }
        }
    }
    int p, k, a, b, c;
    cin >> p >> k >> a >> b >> c;
    int last = 0;
    long long fans = 0;
    for (int i = 0; i < p; ++i)
    {
        cin >> last;
        int pos = lower_bound(Q.begin(), Q.end(), last) - Q.begin();
        fans ^= ans[pos][0] + ans[pos][1] * last;
    }
    for (int i = p; i < k; ++i)
    {
        last = ((long long)last * a + b) % c;
        int pos = lower_bound(Q.begin(), Q.end(), last) - Q.begin();
        fans ^= ans[pos][0] + ans[pos][1] * last;
    }
    cout << fans;
    return 0;
}
