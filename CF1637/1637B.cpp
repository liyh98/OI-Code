#include <bits/stdc++.h>
using namespace std;

int a[101], f[101][101];

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
        long long ans = 0;
        for (int len = 1; len <= n; len++)
        {
            for (int l = 1; l + len - 1 <= n; l++)
            {
                int r = l + len - 1;
                vector<bool> v(len);
                for (int i = l; i <= r; i++)
                {
                    if (a[i] < len)
                        v[a[i]] = 1;
                }
                f[l][r] = 0;
                while (f[l][r] < len && v[f[l][r]])
                    f[l][r]++;
                f[l][r]++;
                for (int i = l; i < r; i++)
                    f[l][r] = max(f[l][r], f[l][i] + f[i + 1][r]);
                ans += f[l][r];
            }
        }
        cout << ans << '\n';
    }
    return 0;
}
