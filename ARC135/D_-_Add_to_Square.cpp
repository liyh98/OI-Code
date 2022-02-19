#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int n, m;
    cin >> n >> m;
    vector<vector<long long>> a(n, vector<long long>(m)), b(n, vector<long long>(m));
    for (auto &v : a)
        for (auto &x : v)
            cin >> x;
    vector<long long> sx(n), sy(m);
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
        {
            sx[i] += a[i][j] * ((i ^ j) & 1 ? 1 : -1);
            sy[j] += a[i][j] * ((i ^ j) & 1 ? 1 : -1);
        }

    long long ans = 0;
    auto op = [&](int x, int y, long long val)
    {
        sx[x] -= val;
        sy[y] -= val;
        ans += abs(val);
        b[x][y] += val;
    };
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
        {
            if (sx[i] < 0 && sy[j] < 0)
                op(i, j, max(sx[i], sy[j]));
            if (sx[i] > 0 && sy[j] > 0)
                op(i, j, min(sx[i], sy[j]));
        }
    for (int i = 0; i < n; i++)
        op(i, 0, sx[i]);
    for (int j = 0; j < m; j++)
        op(0, j, sy[j]);
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            b[i][j] *= ((i ^ j) & 1 ? 1 : -1);
    cout << ans << '\n';
    for (auto &v : b)
    {
        for (auto &x : v)
            cout << x << ' ';
        cout << '\n';
    }
    return 0;
}
