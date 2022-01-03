#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    string x;
    cin >> x;
    int n = x.length();
    vector<int> a(n + 101), ans(n + 101);
    for (int i = 1; i <= n; i++)
        a[i] = x[n - i] - '0';
    int now = 0;
    for (int i = 1; i <= n; i++)
        now += a[i];
    for (int i = 1; i <= n; i++)
    {
        ans[i] = now;
        now -= a[i];
    }
    int len = 1;
    while (len <= n || ans[len])
    {
        ans[len + 1] += ans[len] / 10;
        ans[len] %= 10;
        ++len;
    }
    while (--len)
        cout << ans[len];
    return 0;
}
