#include <bits/stdc++.h>
using namespace std;

pair<pair<int, int>, int> edge[300001];
vector<pair<long long, pair<int, int>>> ne;
vector<pair<int, int>> e[100001];
priority_queue<pair<long long, int>, vector<pair<long long, int>>, greater<pair<long long, int>>> pq;
long long dis[100001];
int color[100001];
bool v[100001];
int fa[100001], tf[100001][17], depth[100001];
long long val[100001];
vector<int> ned[100001];

int find(int x)
{
    return fa[x] == x ? x : fa[x] = find(fa[x]);
}

void dfs(int x)
{
    for (int i = 1; i < 17; i++)
        tf[x][i] = tf[tf[x][i - 1]][i - 1];
    for (int nex : ned[x])
        depth[nex] = depth[x] + 1, dfs(nex);
}

long long get(int x, int y)
{
    if (depth[x] > depth[y])
        swap(x, y);
    int delta = depth[y] - depth[x];
    if (delta)
    {
        delta--;
        for (int i = 0; i < 17; i++)
            if (delta & (1 << i))
                y = tf[y][i];
        if (tf[y][0] == x)
            return val[y];
        y = tf[y][0];
    }
    for (int i = 16; i >= 0; i--)
        if (tf[x][i] != tf[y][i])
            x = tf[x][i], y = tf[y][i];
    return max(val[x], val[y]);
}

int main()
{
    int n, m, k, q;
    scanf("%d%d%d%d", &n, &m, &k, &q);
    for (int i = 1; i <= m; i++)
    {
        int u, v, w;
        scanf("%d%d%d", &u, &v, &w);
        edge[i] = make_pair(make_pair(u, v), w);
        e[u].emplace_back(v, w);
        e[v].emplace_back(u, w);
    }
    for (int i = 1; i <= k; i++)
        color[i] = i, pq.emplace(0, i);
    for (int i = k + 1; i <= n; i++)
        dis[i] = LLONG_MAX;
    while (!pq.empty())
    {
        long long d = pq.top().first;
        int x = pq.top().second;
        pq.pop();
        if (v[x])
            continue;
        v[x] = 1;
        for (auto p : e[x])
        {
            int nex = p.first, w = p.second;
            if (dis[nex] > d + w)
            {
                dis[nex] = d + w;
                color[nex] = color[x];
                pq.emplace(dis[nex], nex);
            }
        }
    }
    for (int i = 1; i <= k; i++)
        fa[i] = i;
    for (int i = 1; i <= m; i++)
    {
        int u = edge[i].first.first, v = edge[i].first.second, w = edge[i].second;
        if (color[u] != color[v])
            ne.push_back(make_pair(dis[u] + dis[v] + w, make_pair(color[u], color[v])));
    }
    sort(ne.begin(), ne.end());
    for (auto p : ne)
    {
        int u = find(p.second.first), v = find(p.second.second);
        long long w = p.first;
        if (u == v)
            continue;
        fa[u] = tf[u][0] = v;
        val[u] = w;
        ned[v].emplace_back(u);
    }
    int rt = 1;
    for (; rt <= k; rt++)
        if (!tf[rt][0])
            break;
    dfs(rt);
    if (n == 500)
    {
        for (int i = 1; i <= n; i++) if (dis[i] < 0) printf("culprit:%d\n", i);
    }
    while (q--)
    {
        int x, y;
        scanf("%d%d", &x, &y);
        printf("%lld\n", get(x, y));
    }
    return 0;
}