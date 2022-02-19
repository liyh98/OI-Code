#include <bits/stdc++.h>
using namespace std;

#define MOD 998244353

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    long long n, p, nex, ans = 0, inv2 = (1ll + MOD) >> 1;
    cin >> n;
    for (p = 1, nex = 10; nex <= n; p = nex, nex *= 10)
    {
        long long d = (nex - p) % MOD;
        (ans += (d + 1) * d % MOD * inv2) %= MOD;
    }
    long long d = (n - p + 1) % MOD;
    (ans += (d + 1) * d % MOD * inv2) %= MOD;
    cout << ans;
    return 0;
}
