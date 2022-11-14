/*
 * @Author: Yuhao.Li
 * @Date: 2022-02-20 12:29:59
 * @Last Modified by:   Yuhao.Li
 * @Last Modified time: 2022-02-20 12:29:59
 */
#include <bits/stdc++.h>
using namespace std;

inline void TC()
{
    int n, m;
    cin >> n >> m;
    long long ans = LLONG_MIN, now = 0, sum = 0;
    for (int i = 1; i <= n; i++)
    {
        long long x, y;
        cin >> x >> y;
        if (sum <= 0)
        {
            ans = max(ans, now + sum + x);
            now += (sum + x + sum + x * y) * y >> 1;
            sum += x * y;
            ans = max(ans, now);
        }
        else if (x >= 0)
        {
            now += (sum + x + sum + x * y) * y >> 1;
            sum += x * y;
            ans = max(ans, now);
        }
        else
        {
            if (sum / (-x) < y)
            {
                long long t = sum / (-x);
                // cout << i << " t=" << t << '\n';
                ans = max(ans, now + ((sum + x + sum + x * t) * t >> 1));
            }
            now += (sum + x + sum + x * y) * y >> 1;
            sum += x * y;
            ans = max(ans, now);
        }
        // cout << ans << ' ' << now << ' ' << sum << '\n';
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
