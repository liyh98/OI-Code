#include <bits/stdc++.h>
using namespace std;

int c[300001], s[300001], tot;
vector<int> e[300001];
bool u[300001], d[300001], p[300001];

void dfs(int x, int pre = 0)
{
    s[x] = c[x];
    p[x] = c[x] | c[pre];
    for (int &nex : e[x])
    {
        if (nex == pre)
            continue;
        dfs(nex, x);
        s[x] += s[nex];
        p[x] |= c[nex];
    }
}

void dp(int x, int pre = 0)
{
    u[x] = u[pre];
    if (p[pre] && tot - s[x] > 1)
        u[x] = 1;
    for (int &nex : e[x])
    {
        if (nex == pre)
            continue;
        dp(nex, x);
        d[x] |= d[nex];
        if (p[nex] && s[nex] > 1)
            d[x] = 1;
    }
}

void propagate(int x, bool ok = 0, int pre = 0)
{
    u[x] |= ok;
    u[x] |= u[pre];
    int sum = 0;
    for (int &nex : e[x])
        if (nex != pre)
            sum += d[nex] | (p[nex] && s[nex] > 1);
    for (int &nex : e[x])
    {
        if (nex == pre)
            continue;
        propagate(nex, sum - (d[nex] | (p[nex] && s[nex] > 1)), x);
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++)
        cin >> c[i], tot += c[i];
    for (int i = 1; i < n; i++)
    {
        int u, v;
        cin >> u >> v;
        e[u].push_back(v);
        e[v].push_back(u);
    }
    dfs(1);
    dp(1);
    propagate(1);
    for (int i = 1; i <= n; i++)
        cout << (u[i] | d[i] | p[i]) << ' ';
    return 0;
}
