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
        vector<int> a(n + 1);
        for (int i = 1; i <= n; i++)
        {
            int x;
            cin >> x;
            a[x]++;
        }
        set<int> s;
        s.insert(0);
        int ans = n << 2;
        for (int i = 1; i <= n; i++)
        {
            a[i] += a[i - 1];
            if (a[i] == a[i - 1])
                continue;
            s.insert(a[i]);
            for (int j = 1; j <= a[i] << 1; j <<= 1)
            {
                auto it = s.upper_bound(j);
                int f = *(--it);
                ans = min(ans, j + (int)pow(2, a[i] == f ? 0 : ceil(log2(a[i] - f))) + (int)pow(2, a[i] == n ? 0 : ceil(log2(n - a[i]))) - n);
                it = s.lower_bound(a[i] - j);
                f = *it;
                ans = min(ans, (int)pow(2, !f ? 0 : ceil(log2(f))) + j + (int)pow(2, a[i] == n ? 0 : ceil(log2(n - a[i]))) - n);
            }
        }
        cout << ans << '\n';
    }
    return 0;
}
