#include <bits/stdc++.h>
using namespace std;

#define MOD 998244353
int x[200001], y[200001];
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int T;
    cin >> T;
    while (T--)
    {
        int n, m, k, q;
        cin >> n >> m >> k >> q;
        unordered_set<int> row, col;
        for (int i = 1; i <= q; i++)
            cin >> x[i] >> y[i];
        long long ans = 1;
        for (int i = q; i; i--)
        {
            if (row.find(x[i]) == row.end() || col.find(y[i]) == col.end())
            {
                (ans *= k) %= MOD;
                row.insert(x[i]);
                col.insert(y[i]);
                if (row.size() == n || col.size() == m)
                    break;
            }
        }
        cout << ans << '\n';
    }
    return 0;
}
