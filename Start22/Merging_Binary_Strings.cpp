#include <bits/stdc++.h>
using namespace std;

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
        string a, b;
        cin >> a >> b;
        vector<int> sa(n + 1), sb(n + 1);
        int ans = 0;
        for (int i = 1; i <= n; i++)
        {
            sa[i] = sa[i - 1] + (a[i - 1] == '1');
            if (a[i - 1] == '0')
                ans += sa[i];
            sb[i] = sb[i - 1] + (b[i - 1] == '1');
            if (b[i - 1] == '0')
                ans += sb[i];
        }
        vector<vector<int>> f(n + 1, vector<int>(n + 1, n * n));
        f[0][0] = 0;
        for (int i = 0; i <= n; i++)
            for (int j = 0; j <= n; j++)
            {
                if (i)
                    f[i][j] = min(f[i][j], f[i - 1][j] + (a[i - 1] == '0') * sb[j]);
                if (j)
                    f[i][j] = min(f[i][j], f[i][j - 1] + (b[j - 1] == '0') * sa[i]);
            }
        cout << ans + f[n][n] << '\n';
    }
    return 0;
}
