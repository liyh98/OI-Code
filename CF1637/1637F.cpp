#include <bits/stdc++.h>
using namespace std;

int d[200001], lf;
long long ans;
vector<int> e[200001];

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++)
        cin >> h[i];
    for (int i = 1; i < n; i++)
    {
        int u, v;
        cin >> u >> v;
        e[u].push_back(v);
        e[v].push_back(u);
        ++d[u];
        ++d[v];
    }
    if (n == 2)
    {
        cout << max(h[1], h[2]) * 2;
    }
    else
    {
        int rt = 0;
        for (int i = 1; i <= n; i++)
            if (d[i] > 1)
            {
                rt = i;
            }
            else
                ++lf;
        dfs(rt, 0);
    }
    return 0;
}
