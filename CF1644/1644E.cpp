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
        string s;
        cin >> n >> s;
        int m = s.length();
        int x = 1, y = 1;
        long long ans = 0;
        for (char c : s)
        {
            if (c == 'D')
                x++;
            else
                y++;
        }
        char c1 = s[0], c2 = (int)'D' + 'R' - c1;
        int now = 0;
        while (now < m && s[now] == c1)
            now++;
        if (now == m)
            ans = n;
        else
        {
            int sum1 = 0, sum2 = 0;
            for (int i = 0; i < m; i++)
            {
                if (s[i] == c1)
                    sum1++;
            }
            ans = n + sum1;
            ans += (long long)n * (c1 == 'D' ? n - x : n - y);
            ans += (long long)((c1 == 'D' ? x : y) - now - 1) * (c1 == 'D' ? n - y : n - x);
        }
        cout << ans << '\n';
    }
    return 0;
}
