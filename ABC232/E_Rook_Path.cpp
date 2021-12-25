#include <bits/stdc++.h>
using namespace std;

#define MOD 998244353

long long f[2][2][2];

inline void add(long long &x, long long y)
{
    x += y;
    if (x >= MOD)
        x -= MOD;
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int h, w, k, x1, x2, y1, y2, o = 0;
    cin >> h >> w >> k >> x1 >> y1 >> x2 >> y2;
    f[0][x1 == x2][y1 == y2] = 1;
    for (int i = 1; i <= k; i++, o ^= 1)
    {
        memset(f[!o], 0, sizeof f[!o]);
        for (int j = 0; j < 2; j++)
            for (int k = 0; k < 2; k++)
            {
                if (!j)
                {
                    add(f[!o][0][k], f[o][0][k] * (h - 2) % MOD);
                    add(f[!o][1][k], f[o][0][k]);
                }
                else
                {
                    add(f[!o][0][k], f[o][1][k] * (h - 1) % MOD);
                }
                if (!k)
                {
                    add(f[!o][j][0], f[o][j][0] * (w - 2) % MOD);
                    add(f[!o][j][1], f[o][j][0]);
                }
                else
                {
                    add(f[!o][j][0], f[o][j][1] * (w - 1) % MOD);
                }
            }
    }
    cout << f[o][1][1];
    return 0;
}
