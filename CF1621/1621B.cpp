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
        int l = INT_MAX, r = 0, b = INT_MAX, bl = INT_MAX, br = INT_MAX;
        for (int i = 1; i <= n; i++)
        {
            int x, y, c;
            cin >> x >> y >> c;
            if (x < l)
                l = x, bl = c, b = INT_MAX;
            if (y > r)
                r = y, br = c, b = INT_MAX;
            if (x == l)
                bl = min(bl, c);
            if (y == r)
                br = min(br, c);
            if (x == l && y == r)
                b = min(b, c);
            cout << min(b, bl + br) << '\n';
        }
    }
    return 0;
}
