#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin >> n;
    vector<vector<int>> a(n, vector<int>(n));
    for (auto &v : a)
    {
        for (auto &x : v)
        {
            cin >> x;
        }
    }
    vector<vector<unordered_map<int, int>>> lu(n, vector<unordered_map<int, int>>(n)), rd(n, vector<unordered_map<int, int>>(n));
    auto calc_diagonal = [&](vector<vector<unordered_map<int, int>>> &res)
    {
        res[0][0][a[0][0]] = 1;
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; i + j < n; j++)
            {
                if (i > 0)
                {
                    for (auto &[x, v] : res[i - 1][j])
                    {
                        res[i][j][x ^ a[i][j]] += v;
                    }
                }
                if (j > 0)
                {
                    for (auto &[x, v] : res[i][j - 1])
                    {
                        res[i][j][x ^ a[i][j]] += v;
                    }
                }
            }
        }
    };
    calc_diagonal(lu);
    for (auto &v : a)
        reverse(v.begin(), v.end());
    reverse(a.begin(), a.end());
    calc_diagonal(rd);
    long long ans = 0;
    for (int i = 0; i < n; i++)
    {
        int j = n - 1 - i;
        for (auto &[x, v] : lu[i][j])
        {
            ans += 1LL * v * rd[j][i][x ^ a[j][i]];
        }
    }
    cout << ans << '\n';
    return 0;
}
