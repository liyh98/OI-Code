#include <bits/stdc++.h>
using namespace std;

int s[51][51], f[51][51][51][51];

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin >> n;
    vector<string> a(n);
    for (auto &x : a)
        cin >> x;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)
            s[i][j] = s[i - 1][j] + s[i][j - 1] - s[i - 1][j - 1] + (a[i - 1][j - 1] == '#');
    /* for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
            cout << s[i][j] << ' ';
        cout << '\n';
    } */
    for (int i = 1; i <= n; i++)
        for (int j = i; j <= n; j++)
            for (int k = 1; k <= n; k++)
                for (int l = k; l <= n; l++)
                {
                    if (s[j][l] - s[i - 1][l] - s[j][k - 1] + s[i - 1][k - 1])
                        f[i][j][k][l] = max(j - i + 1, l - k + 1);
                }
    int ans = 0;
    for (int w = 1; w <= n; w++)
        for (int i = 1; i + w - 1 <= n; i++)
        {
            int j = i + w - 1;
            for (int h = 1; h <= n; h++)
                for (int k = 1; k + h - 1 <= n; k++)
                {
                    int r = k + h - 1;
                    for (int l = i; l < j; l++)
                        ans++, f[i][j][k][r] = min(f[i][j][k][r], f[i][l][k][r] + f[l + 1][j][k][r]);
                    for (int l = k; l < r; l++)
                        ans++, f[i][j][k][r] = min(f[i][j][k][r], f[i][j][k][l] + f[i][j][l + 1][r]);
                    // printf("f[%d][%d][%d]=%d\n", i, j, k, f[i][j][k]);
                }
        }
    cout << f[1][n][1][n];
    return 0;
}
