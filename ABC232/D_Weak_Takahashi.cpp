#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int h, w;
    cin >> h >> w;
    vector<string> c(h);
    for (int i = 0; i < h; i++)
        cin >> c[i];
    vector<vector<bool>> f(h + 1, vector<bool>(w + 1));
    f[0][1] = 1;
    int ans = 0;
    for (int i = 1; i <= h; i++)
        for (int j = 1; j <= w; j++)
            if (c[i - 1][j - 1] == '.')
            {
                f[i][j] = f[i - 1][j] | f[i][j - 1];
                if (f[i][j])
                    ans = max(ans, i + j - 1);
            }
    cout << ans;
    return 0;
}
