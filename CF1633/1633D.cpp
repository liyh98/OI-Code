#include <bits/stdc++.h>
using namespace std;

int d[1001];

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    for (int i = 2; i <= 1000; ++i)
        d[i] = i - 1;
    for (int i = 1; i < 1000; ++i)
    {
        for (int j = 1; j <= i; j = i / (i / j) + 1)
            if (i + i / j <= 1000)
                d[i + i / j] = min(d[i + i / j], d[i] + 1);
    }
    int T;
    cin >> T;
    while (T--)
    {
        int n, k;
        cin >> n >> k;
        vector<int> b(n);
        int s = 0, ans = 0;
        for (int &x : b)
            cin >> x, s += d[x];
        s = min(s, k);
        vector<int> f(s + 1);
        for (int &x : b)
        {
            int y;
            cin >> y;
            for (int i = s; i >= d[x]; --i)
                f[i] = max(f[i], f[i - d[x]] + y);
        }
        for (int i = 0; i <= s; ++i)
            ans = max(ans, f[i]);
        cout << ans << '\n';
    }
    return 0;
}
