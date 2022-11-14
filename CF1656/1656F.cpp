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
        vector<int> a(n);
        for (int &x : a)
            cin >> x;
        sort(a.begin(), a.end());
        long long b = 0, k = 0;
        for (int i = 1; i < n; i++)
        {
            b += (long long)a[0] * a[i];
            k += a[0] + a[i];
        }
        if (k > 0)
        {
            cout << "INF\n";
            continue;
        }
        long long ans = k * (-a[1]) + b;
        for (int i = 1; i < n - 1; i++)
        {
            b += (long long)(a[n - 1] - a[0]) * a[i];
            k += a[n - 1] - a[0];
            if (k > 0)
                ans = max(ans, k * (-a[i]) + b);
            else
                ans = max(ans, k * (-a[i + 1]) + b);
        }
        if (k < 0)
        {
            cout << "INF\n";
            continue;
        }
        cout << ans << '\n';
    }

    return 0;
}
