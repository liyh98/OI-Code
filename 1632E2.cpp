#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> e;
vector<int> f;

int dfs(int x, int pre = 0, int d = 0)
{
    int m1 = d, m2 = d;
    for (int &nex : e[x])
    {
        if (nex == pre)
            continue;
        int ret = dfs(nex, x, d + 1);
        if (m1 < ret)
            m2 = m1, m1 = ret;
        else if (m2 < ret)
            m2 = ret;
    }
    f[m2 - 1] = max(f[m2 - 1], m1 + m2 - d - d + 1);
    return m1;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int T;
    cin >> T;
    while (T--)
    {
        int n;
        cin >> n;
        e.assign(n + 1, {});
        f.assign(n, 0);
        for (int i = 1; i < n; ++i)
        {
            int u, v;
            cin >> u >> v;
            e[u].push_back(v);
            e[v].push_back(u);
        }
        int mAns = dfs(1), ans = 1;
        for (int i = mAns - 2; i >= 0; --i)
            f[i] = max(f[i], f[i + 1]);
        for (int i = 1; i <= n; ++i)
        {
            while (ans < mAns && f[ans] / 2 + i > ans)
                ans++;
            cout << ans << ' ';
        }
        cout << '\n';
    }
    return 0;
}
