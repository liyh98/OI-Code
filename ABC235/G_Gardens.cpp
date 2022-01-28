#include <bits/stdc++.h>
using namespace std;

#define MOD 998244353

long long fac[5000001], invfac[5000001];

long long qpow(long long base, long long expo)
{
    long long ret = 1;
    for (; expo; expo >>= 1, base = base * base % MOD)
        if (expo & 1)
            ret = ret * base % MOD;
    return ret;
}

long long C(int n, int m)
{
    return fac[n] * invfac[m] % MOD * invfac[n - m] % MOD;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int n, a, b, c;
    cin >> n >> a >> b >> c;
    fac[0] = 1;
    for (int i = 1; i <= n; i++)
        fac[i] = fac[i - 1] * i % MOD;
    invfac[n] = qpow(fac[n], MOD - 2);
    for (int i = n - 1; i >= 0; i--)
        invfac[i] = invfac[i + 1] * (i + 1) % MOD;
    long long ans = 0, sa = 1, sb = 1, sc = 1;
    for (int i = 0; i <= n; i++)
    {
        long long t = (n - i) & 1 ? MOD - 1 : 1;
        t = t * C(n, i) % MOD;
        t = t * sa % MOD * sb % MOD * sc % MOD;
        ans = (ans + t) % MOD;
        sa = (sa << 1) % MOD;
        if (i >= a)
            sa = (sa + MOD - C(i, a)) % MOD;
        sb = (sb << 1) % MOD;
        if (i >= b)
            sb = (sb + MOD - C(i, b)) % MOD;
        sc = (sc << 1) % MOD;
        if (i >= c)
            sc = (sc + MOD - C(i, c)) % MOD;
    }
    cout << ans;
    return 0;
}
