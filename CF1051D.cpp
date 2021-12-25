#include <bits/stdc++.h>
using namespace std;

int t[4][4] = {{0, 1, 1, 1}, {0, 0, 2, 0}, {0, 2, 0, 0}, {1, 1, 1, 0}};
int f[2][4][2001];
const int mod = 998244353;
int main()
{
    int n, k, o = 0;
    scanf("%d%d", &n, &k);
    f[0][0][1] = f[0][3][1] = f[0][1][2] = f[0][2][2] = 1;
    for (int i = 2; i <= n; i++)
    {
        memset(f[!o], 0, sizeof f[!o]);
        for (int j = 0; j < 4; j++)
            for (int l = 0; l < 4; l++)
                for (int m = t[j][l]; m <= k; m++)
                    (f[!o][l][m] += f[o][j][m - t[j][l]]) %= mod;
        o ^= 1;
    }
    int ans = 0;
    for (int i = 0; i < 4; i++)
        (ans += f[o][i][k]) %= mod;
    printf("%d", ans);
    return 0;
}