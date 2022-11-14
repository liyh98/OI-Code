#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

#define MOD 998244353ll

ll qpow(ll base, ll expo)
{
    ll ret = 1;
    for (; expo; expo >>= 1, (base *= base) %= MOD)
        if (expo & 1)
            (ret *= base) %= MOD;
    return ret;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int n, k;
    cin >> n >> k;
    --n;
    vector<ll> fac(n + 1), inv(n + 1), invfac(n + 1);
    vector<vector<ll>> f(k + 1, vector<ll>(n + 1));
    fac[0] = invfac[0] = 1;
    fac[1] = inv[1] = invfac[1] = 1;
    for (int i = 2; i <= n; i++)
    {
        inv[i] = MOD - MOD / i * inv[MOD % i] % MOD;
        fac[i] = fac[i - 1] * i % MOD;
        invfac[i] = invfac[i - 1] * inv[i] % MOD;
    }
    f[0][0] = 1;
    for (int i = 1; i <= k; i++)
        for (int j = 0; j <= n; j++)
        {
            for (int l = 0; j + l <= n; l++)
            {
                f[i][j + l] += f[i - 1][j] * invfac[l] % MOD * qpow(k - i + 1, (j + l) * (j + l - 1) / 2 - j * (j - 1) / 2) % MOD;
            }
            f[i][j] %= MOD;
        }
    cout << f[k][n] * fac[n] % MOD;
    return 0;
}
