#include <bits/stdc++.h>
using namespace std;

int a[200001];

inline void TC()
{
    int n;
    long long k, s = 0;
    cin >> n >> k;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
        s += a[i];
    }
    sort(a + 1, a + n + 1);
    s -= k;
    long long ans = max(0ll, s);
    for (int i = 1; i < n; i++)
    {
        s -= a[n + 1 - i] - a[1];
        if (s <= 0)
        {
            ans = min(ans, (long long)i);
            continue;
        }
        long long v = (s - 1) / (i + 1) + 1;
        ans = min(ans, v + i);
        // cout << i << ' ' << s << ' ' << v << '\n';
    }
    cout << ans << '\n';
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int T;
    cin >> T;
    while (T--)
        TC();
    return 0;
}
