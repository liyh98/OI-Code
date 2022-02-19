#include <bits/stdc++.h>
using namespace std;

int a[100001];
long long inv[200];
#define MOD 998244353

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int n, k;
    cin >> n >> k;
    long long tot = 0;
    for (int i = 1; i <= n; i++)
        cin >> a[i], tot += a[i];
    if (a[1] < tot - a[1] + k)
        cout << 0;
    else
    {
        inv[1] = 1;
        for (int i = 2; i < k; i++)
        {
            inv[i] = MOD - inv[MOD % i] * (MOD / i) % MOD;
        }
        long long ans = 1;
        for (int i = 2; i <= n; i++)
        {
            for (int j = 1; j < k; j++)
                ans = ans * (a[i] + k - j) % MOD * inv[j] % MOD;
        }
        long long t = a[1] - (tot - a[1] + k);
        for (int j = 1; j < k; j++)
            ans = ans * (t + k - j) % MOD * inv[j] % MOD;
        cout << ans;
    }
    return 0;
}
