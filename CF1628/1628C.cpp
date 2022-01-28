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
        vector<vector<int>> a(n, vector<int>(n));
        for (auto &v : a)
            for (auto &x : v)
                cin >> x;
        int ans = 0;
        for (int i = 0; i < n; i += 4)
        {
            int x = i, y = 0;
            while (x >= 0 && x < n && y >= 0 && y < n)
            {
                ans ^= a[x][y];
                x -= 2, y += 2;
            }
        }
        for (int i = n % 4 ? 3 : 1; i < n; i += 4)
        {
            int x = n - 1, y = i;
            while (x >= 0 && x < n && y >= 0 && y < n)
            {
                ans ^= a[x][y];
                x -= 2, y += 2;
            }
        }
        reverse(a.begin(), a.end());
        for (int i = 0; i < n; i += 4)
        {
            int x = i, y = 0;
            while (x >= 0 && x < n && y >= 0 && y < n)
            {
                ans ^= a[x][y];
                x -= 2, y += 2;
            }
        }
        for (int i = n % 4 ? 3 : 1; i < n; i += 4)
        {
            int x = n - 1, y = i;
            while (x >= 0 && x < n && y >= 0 && y < n)
            {
                ans ^= a[x][y];
                x -= 2, y += 2;
            }
        }
        cout << ans << '\n';
    }
    return 0;
}
