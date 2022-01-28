#include <bits/stdc++.h>
using namespace std;

#define MOD 998244353

int c[10];

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    string n;
    int m;
    cin >> n;
    cin >> m;
    for (int i = 1; i <= m; i++)
    {
        int x;
        cin >> x;
        c[x] = 1 << (i - 1);
    }
    int full = 1 << m;
    vector<long long> f(full), cnt(full);
    int len = n.length(), d = 0;
    long long cur = 0;
    for (int i = 0; i < len; i++)
    {
        vector<long long> nf(full), ncnt(full);
        for (int b = 0; b < full; b++)
        {
            for (int j = 0; j < 10; j++)
            {
                nf[b | c[j]] = (nf[b | c[j]] + f[b] * 10 + cnt[b] * j) % MOD;
                ncnt[b | c[j]] = (ncnt[b | c[j]] + cnt[b]) % MOD;
            }
        }
        if (i)
        {
            for (int j = 1; j < 10; j++)
            {
                nf[c[j]] = (nf[c[j]] + j) % MOD;
                ncnt[c[j]] = (ncnt[c[j]] + 1) % MOD;
            }
        }
        for (int j = i == 0; j < n[i] - '0'; j++)
        {
            nf[d | c[j]] = (nf[d | c[j]] + cur * 10 + j) % MOD;
            ncnt[d | c[j]] = (ncnt[d | c[j]] + 1) % MOD;
        }
        cur = (cur * 10 + n[i] - '0') % MOD;
        d |= c[n[i] - '0'];
        f = nf;
        cnt = ncnt;
    }
    if (d == full - 1)
        f[d] = (f[d] + cur) % MOD;
    cout << f[full - 1];
    return 0;
}
