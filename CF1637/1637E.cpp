#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int T;
    cin >> T;
    while (T--)
    {
        int n, m;
        cin >> n >> m;
        vector<int> aa(n);
        map<int, int> cnt;
        for (auto &x : aa)
        {
            cin >> x;
            ++cnt[x];
        }
        sort(aa.begin(), aa.end());
        vector<vector<int>> app(n + 1);
        for (auto [n, c] : cnt)
            app[c].push_back(n);
        vector<int> pos;
        for (int i = 1; i <= n; i++)
        {
            if (!app[i].empty())
                pos.push_back(i);
        }
        vector<vector<vector<pair<int, int>>>> weird(pos.size(), vector<vector<pair<int, int>>>(pos.size()));
        vector<pair<int, int>> bad(m);
        for (auto &[x, y] : bad)
        {
            cin >> y >> x;
            if (cnt[x] > cnt[y])
                swap(x, y);
            int a = lower_bound(pos.begin(), pos.end(), cnt[x]) - pos.begin(), b = lower_bound(pos.begin(), pos.end(), cnt[y]) - pos.begin();
            weird[a][b].emplace_back(x, y);
        }
        /*  sort(bad.begin(), bad.end());
                for (auto &[x, y] : bad)
                {
                    weird[lower_bound(aa.begin(), aa.end(), x) - aa.begin()][lower_bound(pos.begin(), pos.end(), cnt[y]) - pos.begin()].push_back(y);
                }
         */
        long long ans = 0;
        for (int i = 0, n = pos.size(); i < n; i++)
            for (int j = i; j < n; j++)
            {
                int x = pos[i], y = pos[j];
                auto &w = weird[i][j];
                sort(w.begin(), w.end());
                int now = w.size() - 1;
                for (int a = app[x].size() - 1; a >= 0 && (long long)(x + y) * (app[x][a] + app[y].back()) > ans; a--)
                {
                    for (int b = x == y ? a - 1 : app[y].size() - 1; b >= 0 && (long long)(x + y) * (app[x][a] + app[y][b]) > ans; b--)
                    {
                        int v1 = app[x][a], v2 = app[y][b];
                        while (now >= 0 && w[now] > make_pair(v1, v2))
                            --now;
                        if (now < 0 || w[now] != make_pair(v1, v2))
                        {
                            ans = (long long)(x + y) * (v1 + v2);
                            break;
                        }
                    }
                }
            }
        cout << ans << '\n';
    }
    return 0;
}
