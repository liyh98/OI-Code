#include <bits/stdc++.h>
using namespace std;

#define MOD 998244353

long long fac[5001], invfac[5001], f[27][5001];

long long qpow(long long base, long long expo)
{
    long long ret = 1;
    for (; expo; expo >>= 1, (base *= base) %= MOD)
        if (expo & 1)
            (ret *= base) %= MOD;
    return ret;
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    string s;
    cin >> s;
    vector<int> cnt(27);
    int n = s.length();
    fac[0] = 1;
    for (int i = 1; i <= n; i++)
        fac[i] = fac[i - 1] * i % MOD;
    invfac[n] = qpow(fac[n], MOD - 2);
    for (int i = n - 1; i >= 0; i--)
        invfac[i] = invfac[i + 1] * (i + 1) % MOD;
    for (char c : s)
        cnt[c - 'a' + 1]++;
    f[0][0] = 1;
    for (int i = 1, sum = 0; i <= 26; i++)
    {
        sum += cnt[i];
        for (int j = 0; j <= cnt[i]; j++)
        {
            for (int s = j; s <= sum; s++)
            {
                (f[i][s] += f[i - 1][s - j] * invfac[j]) %= MOD;
            }
        }
    }
    long long ans = 0;
    for (int i = 1; i <= n; i++)
        (ans += f[26][i] * fac[i]) %= MOD;
    cout << ans;
    return 0;
}
