#include <bits/stdc++.h>
using namespace std;

bool v[5001];
vector<vector<pair<int, int>>> e;
bool c[1001][1001];
int x[5001], y[5001];
vector<int> cur;

bool dfs(int x, int tar)
{
    if (x == tar)
        return 1;
    cur.push_back(x);
    for (auto [nex, eid] : e[x])
    {
        if (!v[eid])
        {
            v[eid] = 1;
            return dfs(nex, tar);
        }
    }
    return 0;
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
        int cnt = 0;
        e.clear();
        e.resize(n + 1);
        memset(c, 0, sizeof c);
        while (m--)
        {
            int u, v, w;
            cin >> u >> v >> w;
            c[u][v] = c[v][u] = 1;
            if (w)
            {
                ++cnt;
                x[cnt] = u;
                y[cnt] = v;
                e[u].emplace_back(v, cnt);
                e[v].emplace_back(u, cnt);
            }
        }
        bool flag = 1;
        vector<vector<int>> ans;
        memset(v, 0, sizeof v);
        for (int i = 1; i <= cnt; i++)
        {
            if (!v[i])
            {
                cur.resize(1, x[i]);
                v[i] = 1;
                if (!dfs(y[i], x[i]))
                {
                    flag = 0;
                    break;
                }
                while (cur.size() >= 3)
                {
                    int r = cur.size();
                    vector<int> ne;
                    bool chord = 0;
                    for (int i = 2; !chord && i < r; i++)
                        for (int j = i - 2; j >= (i == r - 1); j--)
                        {
                            if (!c[cur[i]][cur[j]])
                                continue;
                            chord = 1;
                            vector<int> t;
                            for (int k = j; k <= i; k++)
                                t.push_back(cur[k]);
                            ans.push_back(t);
                            for (int k = 0; k <= j; k++)
                                ne.push_back(cur[k]);
                            for (int k = i; k < r; k++)
                                ne.push_back(cur[k]);
                            break;
                        }
                    if (chord)
                        cur = ne;
                    else
                    {
                        ans.push_back(cur);
                        break;
                    }
                }
            }
        }
        if (!flag)
            puts("-1");
        else
        {
            cout << ans.size() << '\n';
            for (auto &v : ans)
            {
                cout << v.size() << ' ';
                for (int &x : v)
                    cout << x << ' ';
                cout << '\n';
            }
        }
    }
    return 0;
}
