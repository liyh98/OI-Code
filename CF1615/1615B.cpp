#include <bits/stdc++.h>
using namespace std;

int s[200001][20];
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    for (int i = 1; i <= 200000; i++)
    {
        for (int j = 0; j < 18; j++)
            s[i][j] = s[i - 1][j] + ((i >> j) & 1);
    }
    int T;
    cin >> T;
    while (T--)
    {
        int l, r;
        cin >> l >> r;
        int ans = 0;
        for (int i = 0; i < 18; i++)
            ans = max(ans, s[r][i] - s[l - 1][i]);
        cout << r - l + 1 - ans << '\n';
    }
    return 0;
}
