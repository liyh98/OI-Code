#include <bits/stdc++.h>
using namespace std;

#define MOD 998244353

inline void add(int &x, const int &y)
{
    x += y;
    if (x >= MOD)
        x -= MOD;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int n, k;
    cin >> n >> k;
    vector<pair<int, int>> a(n);
    for (auto &[f, s] : a)
        cin >> f;
    for (auto &[f, s] : a)
        cin >> s;
    sort(a.begin(), a.end(), greater());
    vector<vector<int>> f(k + 1, vector<int>(n + 1));
    f[1][a[0].second] = 1;
    for (int i = 1; i < n; i++)
    {
        vector<vector<int>> nf(k + 1, vector<int>(n + 1));
        nf[1][a[i].second] = 1;
        for (int j = k; j; j--)
        {
            for (int l = 1; l <= n; l++)
            {
                if (l >= a[i].second)
                {
                    if (j < k)
                        add(nf[j + 1][l], f[j][l]);
                }
                else
                {
                    nf[j][l] = f[j][l];
                    if (j < k)
                        add(nf[j + 1][a[i].second], f[j][l]);
                }
            }
        }
        f = nf;
    }
    int ans = 0;
    for (int i = k; i <= n; i++)
        add(ans, f[k][i]);
    cout << ans;
    return 0;
}
