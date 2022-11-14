#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int n, s;
    cin >> n >> s;
    vector<vector<bool>> f(n + 1, vector<bool>(s + 1)), side(n + 1, vector<bool>(s + 1));
    f[0][0] = true;
    vector<vector<int>> prev(n + 1, vector<int>(s + 1));
    for (int i = 1; i <= n; i++)
    {
        int a, b;
        cin >> a >> b;
        for (int j = 0; j < s; j++)
        {
            if (f[i - 1][j])
            {
                if (j + a <= s)
                {
                    f[i][j + a] = true;
                    side[i][j + a] = false;
                    prev[i][j + a] = j;
                }
                if (j + b <= s)
                {
                    f[i][j + b] = true;
                    side[i][j + b] = true;
                    prev[i][j + b] = j;
                }
            }
        }
    }
    if (f[n][s])
    {
        cout << 'Y' << 'e' << 's' << '\n';
        string ans(n, 0);
        for (int i = n; i; --i)
        {
            ans[i - 1] = side[i][s] ? 'T' : 'H';
            s = prev[i][s];
        }
        cout << ans << '\n';
    }
    else
    {
        cout << 'N' << 'o' << '\n';
    }
    return 0;
}
