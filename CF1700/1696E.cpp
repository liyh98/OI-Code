#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll inv[400001], fac[400001], facinv[400001];
const int P = 1e9 + 7;

inline ll C(int n, int m)
{
    return (m < 0 || n < m) ? 0 : fac[n] * facinv[m] % P * facinv[n - m] % P;
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    inv[1] = fac[1] = facinv[1] = fac[0] = facinv[0] = 1;
    for (int i = 2; i <= 400000; i++)
    {
        inv[i] = (P - inv[P % i] * (P / i) % P) % P;
        fac[i] = fac[i - 1] * i % P;
        facinv[i] = facinv[i - 1] * inv[i] % P;
    }
    int n, prev = 0;
    cin >> n;
    ll ans = -1;
    for (int i = 1; i <= n + 1; i++)
    {
        int x;
        cin >> x;
        if (i == 1 && !x)
        {
            cout << 0;
            return 0;
        }
        (ans += C(x + i - 2, i - 1)) %= P;
        for (int j = prev; j > x; j--)
            (ans += C(j + i - 3, i - 2)) %= P;
        prev = x;
    }
    for (int i = prev; i; i--)
        (ans += C(i + n - 1, n)) %= P;
    cout << ans;
    return 0;
}
