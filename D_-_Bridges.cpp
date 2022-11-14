#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

vector<vector<tuple<int, int, bool>>> e;
vector<int> a, b;
vector<bool> vv, ve, ans;

void dfs(int x)
{
    vv[x] = 1;
    for (auto [nv, ne, dir] : e[x])
    {
        if (ve[ne])
            continue;
        ans[ne] = dir;
        ve[ne] = 1;
        if (!vv[nv])
            dfs(nv);
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int n, m;
    cin >> n >> m;
    e.resize(n);
    vv.resize(n);
    ve.resize(m);
    ans.resize(m);
    a.resize(m);
    b.resize(m);
    for (int &x : a)
        cin >> x;
    for (int &x : b)
        cin >> x;
    for (int i = 0; i < m; i++)
    {
        e[a[i] - 1].emplace_back(b[i] - 1, i, 0);
        e[b[i] - 1].emplace_back(a[i] - 1, i, 1);
    }
    for (int i = 0; i < n; i++)
    {
        if (!vv[i])
            dfs(i);
    }
    for (bool x : ans)
        cout << (int)x;
    return 0;
}
