#include <bits/stdc++.h>
using namespace std;

#define MOD 998244353

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int n, m;
    cin >> n >> m;
    vector<vector<vector<int>>> f(m + 2, vector<vector<int>>(m + 2, vector<int>(m + 2)));
    f[m + 1][m + 1][m + 1] = 1;
    for (int i = 0; i < n; i++)
    {
        vector<vector<vector<int>>> nf(m + 2, vector<vector<int>>(m + 2, vector<int>(m + 2)));
        for (int v1 = 1; v1 <= m + 1; v1++)
            for (int v2 = v1; v2 <= m + 1; v2++)
                for (int v3 = v2; v3 <= m + 1; v3++)
                {
                    if (!f[v1][v2][v3])
                        continue;
                    for (int v = 1; v <= min(v3, m); v++)
                    {
                        int tv1 = min(v1, v), tv2 = v > v1 ? min(v, v2) : v2, tv3 = v > v2 ? min(v, v3) : v3;
                        (nf[tv1][tv2][tv3] += f[v1][v2][v3]) %= MOD;
                    }
                }
        f = nf;
    }
    int ans = 0;
    for (int v1 = 1; v1 <= m; v1++)
        for (int v2 = v1; v2 <= m; v2++)
            for (int v3 = v2; v3 <= m; v3++)
                (ans += f[v1][v2][v3]) %= MOD;
    cout << ans;
    return 0;
}
