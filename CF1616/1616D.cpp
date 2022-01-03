#include <bits/stdc++.h>
using namespace std;

int d[50001];
int f[50001][2][2];

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
        {
            cin >> d[i];
        }
        int x, ans = max(1, n / 2);
        cin >> x;
        memset(f, 0, sizeof f);
        for (int i = 1; i <= n; i++)
        {
            d[i] -= x;
            for (int a = 0; a <= (i > 2); a++)
                for (int b = 0; b <= (i > 1); b++)
                    for (int c = 0; c <= 1; c++)
                    {
                        if (!c)
                            f[i][b][c] = max(f[i][b][c], f[i - 1][a][b]);
                        else if (!b)
                            f[i][b][c] = max(f[i][b][c], f[i - 1][a][b] + 1);
                        else if (d[i] + d[i - 1] >= 0)
                        {
                            // cout << i << ' ' << a << ' ' << b << ' ' << d[i] << ' ' << d[i - 1] << '\n';
                            if (!a || d[i] + d[i - 1] + d[i - 2] >= 0)
                            {
                                f[i][b][c] = max(f[i][b][c], f[i - 1][a][b] + 1);
                            }
                        }
                        ans = max(ans, f[i][b][c]);
                    }
        }
        cout << ans << '\n';
    }
    return 0;
}
