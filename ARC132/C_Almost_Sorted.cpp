#include <bits/stdc++.h>
using namespace std;

int f[501][1 << 11], a[501];

#define MOD 998244353

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int n, d;
    cin >> n >> d;
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    f[0][0] = 1;
    for (int i = 1; i <= n; i++)
    {
        for (int b = 0; b < 1 << (d << 1 | 1); b++)
        {
            int nex = b >> 1;
            if (a[i] == -1)
            {
                for (int j = max(1 - i, -d); j <= min(n - i, d); j++)
                    if (!((nex >> (j + d)) & 1))
                        (f[i][nex | (1 << (j + d))] += f[i - 1][b]) %= MOD;
            }
            else
            {
                int j = a[i] - i;
                if (!((nex >> (j + d)) & 1))
                    (f[i][nex | (1 << (j + d))] += f[i - 1][b]) %= MOD;
            }
        }
    }
    cout << f[n][(1 << (d + 1)) - 1];
    return 0;
}
