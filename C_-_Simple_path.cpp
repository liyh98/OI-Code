#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int n, x, y;
    cin >> n >> x >> y;
    --x;
    --y;
    vector<vector<int>> e(n);
    for (int i = 1; i < n; ++i)
    {
        int u, v;
        cin >> u >> v;
        --u;
        --v;
        e[u].push_back(v);
        e[v].push_back(u);
    }
    function<bool(int, int)> dfs = [&](int now, int pre) -> bool
    {
        if (now == x)
        {
            cout << x + 1 << ' ';
            return true;
        }
        for (auto nex : e[now])
        {
            if (nex == pre)
                continue;
            if (dfs(nex, now))
            {
                cout << now + 1 << ' ';
                return true;
            }
        }
        return false;
    };
    dfs(y, -1);
    return 0;
}
