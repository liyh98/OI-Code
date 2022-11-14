/*
 * @Author: Yuhao.Li
 * @Date: 2022-02-20 12:07:17
 * @Last Modified by: Yuhao.Li
 * @Last Modified time: 2022-02-20 12:12:45
 */
#include <bits/stdc++.h>
using namespace std;

vector<int> e[200001];
int T, in[200001], out[200001];

void dfs(int x, int pre)
{
    if (e[x].size() == 1 && e[x][0] == pre)
    {
        in[x] = ++T;
        out[x] = T;
        return;
    }
    for (int &nex : e[x])
    {
        if (nex != pre)
        {
            dfs(nex, x);
            if (!in[x])
                in[x] = in[nex];
            out[x] = max(out[x], out[nex]);
        }
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin >> n;
    for (int i = 1; i < n; i++)
    {
        int u, v;
        cin >> u >> v;
        e[u].push_back(v);
        e[v].push_back(u);
    }
    dfs(1, 0);
    for (int i = 1; i <= n; i++)
        cout << in[i] << ' ' << out[i] << '\n';
    return 0;
}
