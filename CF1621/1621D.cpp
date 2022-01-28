#include <bits/stdc++.h>
using namespace std;

int c[501][501];

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
        int dbl = n << 1;
        for (int i = 1; i <= dbl; i++)
            for (int j = 1; j <= dbl; j++)
                cin >> c[i][j];
        long long ans = 0;
        for (int i = n + 1; i <= dbl; i++)
            for (int j = n + 1; j <= dbl; j++)
                ans += c[i][j];
        int best = INT_MAX;
        best = min(best, c[n + 1][1]);
        best = min(best, c[n + 1][n]);
        best = min(best, c[dbl][1]);
        best = min(best, c[dbl][n]);
        best = min(best, c[1][n + 1]);
        best = min(best, c[n][n + 1]);
        best = min(best, c[1][dbl]);
        best = min(best, c[n][dbl]);
        cout << ans + best << '\n';
    }
    return 0;
}
