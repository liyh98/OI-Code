#include <bits/stdc++.h>
using namespace std;

inline void TC()
{
    int n;
    string a, b;
    cin >> n;
    cin >> a;
    cin >> b;
    int ca = 0, cb = 0;
    for (char &c : a)
        ca += c == '1';
    for (char &c : b)
        cb += c == '1';
    if (ca != cb && ca + cb != n + 1)
        cout << "-1\n";
    else
    {
        int ans = INT_MAX;
        if (ca == cb)
        {
            int cnt = 0;
            for (int i = 0; i < n; i++)
                cnt += a[i] != b[i];
            ans = min(ans, cnt);
        }
        if (ca + cb == n + 1)
        {
            int cnt = 0;
            for (int i = 0; i < n; i++)
                cnt += a[i] == b[i];
            ans = min(ans, cnt);
        }
        cout << ans << '\n';
    }
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int T;
    cin >> T;
    while (T--)
        TC();
    return 0;
}
