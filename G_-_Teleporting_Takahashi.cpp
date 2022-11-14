#include <bits/stdc++.h>
#include <atcoder/convolution>
#include <atcoder/modint>
using namespace atcoder;
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int n, x, y, z;
    cin >> n >> x >> y >> z;
    x = abs(x), y = abs(y), z = abs(z);
    if (x + y + z > n || (x ^ y ^ z ^ n) & 1)
    {
        cout << 0;
        return 0;
    }
    int m = (n - x - y - z) >> 1;
    const int N = max(n, m + max(x, max(y, z)));
    vector<modint998244353> fac(N + 1);
    fac[0] = 1;
    for (int i = 1; i <= N; i++)
        fac[i] = fac[i - 1] * i;
    vector<modint998244353> invfac(N + 1);
    invfac[N] = 1 / fac[N];
    for (int i = N; i; i--)
        invfac[i - 1] = invfac[i] * i;
    modint998244353 ans;
    if (m >= (1 << 22))
    {
        int half = (m + 1) >> 1;
        vector<modint998244353> a1(half), a2(m + 1 - half), b(m + 1);
        for (int i = 0; i < half; i++)
            a1[i] = invfac[i] * invfac[i + x];
        for (int i = half; i < m + 1; i++)
            a2[i - half] = invfac[i] * invfac[i + x];
        for (int i = 0; i <= m; i++)
            b[i] = invfac[i] * invfac[i + y];
        auto res1 = convolution(a1, b);
        auto res2 = convolution(a2, b);
        for (int i = 0; i <= m; i++)
            ans += res1[i] * invfac[m - i] * invfac[m - i + z];
        for (int i = half; i <= m; i++)
            ans += res2[i - half] * invfac[m - i] * invfac[m - i + z];
    }
    else
    {
        vector<modint998244353> a(m + 1), b(m + 1);
        for (int i = 0; i <= m; i++)
            a[i] = invfac[i] * invfac[i + x];
        for (int i = 0; i <= m; i++)
            b[i] = invfac[i] * invfac[i + y];
        auto res = convolution(a, b);
        for (int i = 0; i <= m; i++)
            ans += res[i] * invfac[m - i] * invfac[m - i + z];
    }
    ans *= fac[n];
    cout << ans.val();
    return 0;
}
