#include <bits/stdc++.h>
using namespace std;

inline bool judge(string s)
{
    for (int i = 0, n = s.length() - 1; i + i < n; ++i)
        if (s[i] != s[n - i])
            return true;
    return false;
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
    while (t--)
    {
        int n, k;
        string s;
        cin >> n >> k >> s;
        cout << 1 + (k > 0) * judge(s) << '\n';
    }
    return 0;
}
