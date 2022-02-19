#include <bits/stdc++.h>
using namespace std;

int a[10001], l[10001], r[10002];

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
        for (int i = 1; i <= n; i++)
            cin >> a[i];
        for (int i = 1; i <= n; i++)
            l[i] = max(l[i - 1], a[i]);
        r[n + 1] = 1e9;
        for (int i = n; i; i--)
            r[i] = min(r[i + 1], a[i]);
        bool ans = 0;
        for (int i = 1; i <= n; i++)
        {
            if (l[i] > r[i + 1])
            {
                ans = 1;
                break;
            }
        }
        puts(ans ? "YES" : "NO");
    }
    return 0;
}
