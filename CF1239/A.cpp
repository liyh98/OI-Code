#include <bits/stdc++.h>
using namespace std;

int f[100001][4];
const int mod = 1000000007;

long long ksm(long long b, int e)
{
    long long ret = 1;
    for (; e; e >>= 1, (b *= b) % mod)
        if (e & 1)
            (ret *= b) %= mod;
    return ret;
}
int main()
{
    int n, m;
    scanf("%d%d", &n, &m);
    f[1][1] = f[1][2] = 1;
    for (int i = 2; i <= n; i++)
    {
        f[i][0] = f[i - 1][2];
        f[i][1] = (f[i - 1][0] + f[i - 1][2]) % mod;
        f[i][2] = (f[i - 1][1] + f[i - 1][3]) % mod;
        f[i][3] = f[i - 1][1];
    }
    int sum = 0;
    for (int i = 0; i < 4; i++)
        (sum += f[n][i]) %= mod;
    (sum += mod - 2) %= mod;
    f[1][1] = f[1][2] = 1;
    for (int i = 2; i <= m; i++)
    {
        f[i][0] = f[i - 1][2];
        f[i][1] = (f[i - 1][0] + f[i - 1][2]) % mod;
        f[i][2] = (f[i - 1][1] + f[i - 1][3]) % mod;
        f[i][3] = f[i - 1][1];
    }
    int tot = 0;
    for (int i = 0; i < 4; i++)
        (sum += f[m][i]) %= mod;
    printf("%d", sum);
    return 0;
}