#include <bits/stdc++.h>
using namespace std;

vector<pair<int, int>> e[1001], re[1001];
priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
int dis[1001], rdis[1001];
int main()
{
    int n, m;
    scanf("%d%d", &n, &m);
    while (m--)
    {
        int u, v, w;
        scanf("%d%d%d", &u, &v, &w);
        e[u].emplace_back(v, w);
        re[v].emplace_back(u, w);
    }
    pq.emplace(0, 1);
    for (int i = 2; i <= n; i++)
        rdis[i] = dis[i] = INT_MAX;
    while (!pq.empty())
    {
        int u, w;
        tie(w, u) = pq.top();
        pq.pop();
        if (w > dis[u])
            continue;
        for (auto p : e[u])
        {
            if (dis[p.first] > w + p.second)
            {
                dis[p.first] = w + p.second;
                pq.emplace(dis[p.first], p.first);
            }
        }
    }
    pq.emplace(0, 1);
    while (!pq.empty())
    {
        int u, w;
        tie(w, u) = pq.top();
        pq.pop();
        if (w > rdis[u])
            continue;
        for (auto p : re[u])
        {
            if (rdis[p.first] > w + p.second)
            {
                rdis[p.first] = w + p.second;
                pq.emplace(rdis[p.first], p.first);
            }
        }
    }
    long long ans = 0;
    for (int i = 2; i <= n; i++)
        ans += dis[i] + rdis[i];
    printf("%lld", ans);
    return 0;
}