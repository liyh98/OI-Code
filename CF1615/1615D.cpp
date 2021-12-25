#include <bits/stdc++.h>
using namespace std;

int x[200001], y[200001], v[200001];
int parity[200001];

inline void TC()
{
    int n, m;
    cin >> n >> m;
    vector<vector<pair<int, int>>> edges(n + 1, vector<pair<int, int>>());
    for (int i = 1; i < n; i++)
    {
        cin >> x[i] >> y[i] >> v[i];
        if (v[i] > -1)
        {
            edges[x[i]].emplace_back(y[i], __builtin_popcount(v[i]) & 1);
            edges[y[i]].emplace_back(x[i], __builtin_popcount(v[i]) & 1);
        }
    }
    for (int i = 1; i <= m; i++)
    {
        int a, b, p;
        cin >> a >> b >> p;
        edges[a].emplace_back(b, p);
        edges[b].emplace_back(a, p);
    }
    memset(parity, -1, sizeof parity);
    queue<int> q;
    for (int i = 1; i <= n; i++)
    {
        if (parity[i] == -1)
        {
            q.push(i);
            parity[i] = 0;
            while (!q.empty())
            {
                int x = q.front();
                q.pop();
                for (auto &p : edges[x])
                {
                    if (parity[p.first] == -1)
                    {
                        parity[p.first] = parity[x] ^ p.second;
                        q.push(p.first);
                    }
                    else if (parity[x] ^ parity[p.first] != p.second)
                    {
                        cout << "NO" << '\n';
                        return;
                    }
                }
            }
        }
    }
    cout << "YES\n";
    for (int i = 1; i < n; i++)
    {
        cout << x[i] << ' ' << y[i] << ' ';
        if (v[i] > -1)
            cout << v[i] << '\n';
        else
            cout << (parity[x[i]] ^ parity[y[i]]) << '\n';
    }
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int T;
    cin >> T;
    while (T--)
        TC();
    return 0;
}
