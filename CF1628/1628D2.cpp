#include <bits/stdc++.h>
using namespace std;

long long fac[1000001], inv[1000001], po[1000001];
#define MOD 1000000007

long long qpow(long long base, long long expo)
{
    long long ret = 1;
    for (; expo; expo >>= 1, (base *= base) %= MOD)
        if (expo & 1)
            (ret *= base) %= MOD;
    return ret;
}

long long C(int n, int m) { return fac[n] * inv[m] % MOD * inv[n - m] % MOD; }

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int T;
    cin >> T;
    fac[0] = 1;
    long long inv2 = (1ll + MOD) / 2;
    po[0] = 1;
    for (int i = 1; i <= 1000000; i++)
        fac[i] = fac[i - 1] * i % MOD, po[i] = po[i - 1] * inv2 % MOD;
    inv[1000000] = qpow(fac[1000000], MOD - 2);
    for (int i = 999999; i >= 0; i--)
        inv[i] = inv[i + 1] * (i + 1) % MOD;
    while (T--)
    {
        int n, m, k;
        cin >> n >> m >> k;
        long long ans = 0;
        for (int i = 1; i <= m; i++)
            ans += inv2 * (i + 1) % MOD * C(n - i, m - i) % MOD * po[n - i] % MOD;
        ans %= MOD;
        cout << ans * k % MOD << '\n';
    }
    return 0;
}
