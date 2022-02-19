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
        string s;
        cin >> s;
        int n = s.length(), n0 = 0, ans = 0;
        for (int i = 1, now = 0; i <= n; i++)
        {
            now += s[i - 1] == '0' ? -1 : 1;
            if (now)
            {
                if (!n0)
                    n0 = now;
                ans = max(ans, (i - abs(now)) >> 1);
            }
            else if (n0)
                ans = max(ans, (i - abs(n0)) >> 1);
        }
        cout << ans << '\n';
    }
    return 0;
}
