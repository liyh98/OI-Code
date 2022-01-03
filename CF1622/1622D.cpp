#include <bits/stdc++.h>
using namespace std;

#define MOD 998244353

long long fac[5001], inv[5001];

long long qpow(long long base, int expo)
{
    long long ret = 1;
    for (; expo; expo >>= 1, (base *= base) %= MOD)
        if (expo & 1)
            (ret *= base) %= MOD;
    return ret;
}

long long C(int n, int m)
{
    return fac[n] * inv[m] % MOD * inv[n - m] % MOD;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int n, k;
    cin >> n >> k;
    fac[0] = 1;
    for (int i = 1; i <= n; i++)
        fac[i] = fac[i - 1] * i % MOD;
    inv[n] = qpow(fac[n], MOD - 2);
    for (int i = n - 1; i >= 0; i--)
        inv[i] = inv[i + 1] * (i + 1) % MOD;
    string s;
    cin >> s;
    long long ans = 1;
    if (k)
        for (int i = 0, j = 0, c = 0, l = 0; i < n; c--, i++)
        {
            while (c < k && j < n)
            {
                if (s[j] == '1')
                {
                    l = j;
                    c++;
                }
                j++;
            }
            if (c < k)
                break;
            while (s[j] == '0' && j < n)
                j++;
            (ans += C(j - i, k)) %= MOD;
            if (i > 0)
                (ans += MOD - C(l - i, k - 1)) %= MOD;
            else
                ans = (ans + MOD - 1) % MOD;
            // cout << i << ' ' << j << ' ' << l << ' ';
            while (i < n && s[i] != '1')
                i++;
            // cout << ans << '\n';
        }
    cout << ans;
    return 0;
}
