#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int n, m;
    cin >> n >> m;
    if (!m)
    {
        cout << n - 1;
        return 0;
    }
    string s, t;
    cin >> s >> t;
    vector<int> a, b;
    for (int i = 0; i < n + m; i++)
    {
        if (s[i] == '1')
            a.push_back(i);
        if (t[i] == '1')
            b.push_back(i);
    }
    for (int i = 0; i < m; i++)
        if (a[i] > b[i])
            swap(a[i], b[i]);
    int ans = 0, pre = 0;
    //cout << max(0, b[0] - 1) << '\n';
    ans += max(0, b[0] - 1);
    for (int i = 1; i < m; i++)
    {
        if (a[i] - b[pre] > i - pre)
        {
            //cout << i - pre - 1 << ' ' << max(0, b[i] - (b[pre] + i - pre - 1) - 2) << '\n';
            ans += i - pre - 1;
            ans += max(0, b[i] - (b[pre] + i - pre - 1) - 2);
            pre = i;
        }
    }
    //cout << m - pre - 1 << ' ' << max(0, n + m - (b[pre] + m - 1 - pre) - 2) << '\n';
    ans += m - pre - 1;
    ans += max(0, n + m - (b[pre] + m - 1 - pre) - 2);

    int ans1 = ans;
    ans = 0;
    pre = 0;
    //cout << max(0, a[0] - 1) << '\n';
    ans += max(0, a[0] - 1);
    for (int i = 1; i < m; i++)
    {
        if (a[i] - (pre ? b[pre] : a[pre]) > i - pre)
        {
            //cout << i - pre - 1 << ' ' << max(0, b[i] - ((pre ? b[pre] : a[pre]) + i - pre - 1) - 2) << '\n';
            ans += i - pre - 1;
            ans += max(0, b[i] - ((pre ? b[pre] : a[pre]) + i - pre - 1) - 2);
            pre = i;
        }
    }
    //cout << m - pre - 1 << ' ' << max(0, n + m - ((pre ? b[pre] : a[pre]) + m - 1 - pre) - 2) << '\n';
    ans += m - pre - 1;
    ans += max(0, n + m - ((pre ? b[pre] : a[pre]) + m - 1 - pre) - 2);
    // cout << pans;
    //cout << ans << '\n';
    cout << max(ans, ans1);
    return 0;
}

// 0111 0111 1011 1011 1101 0011 0111 1010 1101 10
// 1001 1110 1110 1101 1001 1110 1111 1101 0011 10
// 0111 0111 1011 1001 1111 0011 0111 1100 1101 10