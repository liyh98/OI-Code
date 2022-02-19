#include <bits/stdc++.h>
using namespace std;

int a[101], b[101];

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int T;
    cin >> T;
    while (T--)
    {
        int n, s = 0;
        cin >> n;
        for (int i = 1; i <= n; i++)
            cin >> a[i], s += a[i];
        for (int i = 1; i <= n; i++)
            cin >> b[i], s += b[i];
        vector<bool> f(s + 1);
        f[0] = 1;
        for (int i = 1; i <= n; i++)
        {
            vector<bool> nf(s + 1);
            for (int j = a[i]; j <= s; j++)
                if (f[j - a[i]])
                    nf[j] = 1;
            for (int j = b[i]; j <= s; j++)
                if (f[j - b[i]])
                    nf[j] = 1;
            f = nf;
        }
        int ans = INT_MAX;
        for (int i = 0; i <= s; i++)
            if (f[i])
                ans = min(ans, i * i + (s - i) * (s - i));
        for (int i = 1; i <= n; i++)
            ans += (n - 2) * (a[i] * a[i] + b[i] * b[i]);
        cout << ans << '\n';
    }
    return 0;
}
