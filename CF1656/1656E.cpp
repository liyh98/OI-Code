#include <bits/stdc++.h>
using namespace std;

int ans[100001];
vector<vector<int>> e;

void dfs(int x, int fa, int s)
{
    ans[x] = s;
    for (int &nex : e[x])
    {
        if (nex == fa)
            continue;
        dfs(nex, x, s == 0 ? 1 : -s);
        ans[x] -= s == 0 ? 1 : -s;
    }
}

void dfs2(int x, int fa, int sign)
{
    ans[x] = sign * e[x].size();
    for (int &nex : e[x])
    {
        if (nex == fa)
            continue;
        dfs(nex, x, -sign);
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        e.assign(n + 1, vector<int>());
        for (int i = 1; i < n; i++)
        {
            int x, y;
            cin >> x >> y;
            e[x].push_back(y);
            e[y].push_back(x);
        }
        dfs2(1, 0, 1);
        for (int i = 1; i <= n; i++)
            cout << ans[i] << ' ';
        cout << '\n';
    }
    return 0;
}
