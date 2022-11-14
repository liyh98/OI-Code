#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int a[200001];

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
        ll pos = 0, neg = 0;
        for (int i = n; i; i--)
        {
            a[i] -= a[i - 1];
            if (i > 1)
            {
                if (a[i] > 0)
                    pos += a[i];
                else
                    neg -= a[i];
            }
        }
        ll ans = 0;
        if (a[1] > 0)
        {
            ans = a[1];
            neg -= min(ans, neg);
        }
        else
        {
            ans = -a[1];
        }
        ans += pos;
        ans += neg * 2;
        cout << ans << '\n';
    }
    return 0;
}
