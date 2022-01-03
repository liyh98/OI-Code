#include <bits/stdc++.h>
using namespace std;

int gcd(int x, int y)
{
    return x ? gcd(y % x, x) : y;
}

int a[71];

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int T;
    cin >> T;
    while (T--)
    {
        int n;
        cin >> n;
        for (int i = 1; i <= n; i++)
            cin >> a[i];
        int ans = max(0, n - 2);
        for (int fix1 = 1; fix1 <= n; fix1++)
        {
            for (int fix2 = fix1 + 1; fix2 <= n; fix2++)
            {
                int cnt = n;
                for (int i = fix1; i <= fix2; i++)
                {
                    if ((a[fix2] - a[fix1]) * (i - fix1) == (a[i] - a[fix1]) * (fix2 - fix1))
                        cnt--;
                }
                ans = min(ans, cnt);
            }
        }
        cout << ans << '\n';
    }
    return 0;
}
