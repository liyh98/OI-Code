#include <bits/stdc++.h>
using namespace std;

#define MOD 1000000007
inline long long qpow(long long base, long long expo)
{
    long long ret = 1;
    for (; expo; expo >>= 1, (base *= base) %= MOD)
        if (expo & 1)
            (ret *= base) %= MOD;
    return ret;
}
long long fac[100001], inv[100001];

inline long long C(int n, int m)
{
    return fac[n] * inv[m] % MOD * inv[n - m] % MOD;
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    fac[0] = 1;
    for (int i = 1; i <= 100000; i++)
        fac[i] = fac[i - 1] * i % MOD;
    inv[100000] = qpow(fac[100000], MOD - 2);
    for (int i = 99999; i >= 0; i--)
        inv[i] = inv[i + 1] * (i + 1) % MOD;
    long long inv2 = qpow(2, MOD - 2);
    int T;
    cin >> T;
    while (T--)
    {
        int n;
        cin >> n;
        long long denom = qpow(inv2, n - 1), base = (qpow(2, n) + MOD - 2) % MOD;
        for (int i = 1; i <= n; i++)
        {
            cout << (base + C(n - 1, i - 1)) * denom % MOD << ' ';
        }
        cout << '\n';
    }
    return 0;
}
