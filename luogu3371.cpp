#include <bits/stdc++.h>
using namespace std;

vector<pair<int, int>> e[10001];
queue<int> q;
int dis[10001];
bool inq[10001];
int main()
{
    int n, m, s;
    cin.tie(0);
    cin >> n >> m >> s;
    while (m--)
    {
        int u, v, w;
        cin >> u >> v >> w;
        e[u].emplace_back(v, w);
    }
    q.push(s);
    for (int i = 1; i <= n; i++)
        dis[i] = INT_MAX;
    dis[s] = 0;
    while (!q.empty())
    {
        int u = q.front();
        inq[u] = 0;
        q.pop();
        for (auto p : e[u])
        {
            if (dis[p.first] > dis[u] + p.second)
            {
                dis[p.first] = dis[u] + p.second;
                if (!inq[p.first])
                    inq[p.first] = 1, q.push(p.first);
            }
        }
    }
    for (int i = 1; i <= n; i++)
        printf("%d ", dis[i]);
    return 0;
}