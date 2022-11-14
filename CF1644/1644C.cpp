#include <bits/stdc++.h>
using namespace std;

long long a[5001];

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int T;
    cin >> T;
    while (T--)
    {
        int n, x;
        cin >> n >> x;
        for (int i = 1; i <= n; i++)
            cin >> a[i], a[i] += a[i - 1];
        long long ans = 0;
        for (int i = 0; i <= n; i++)
        {
            long long lowest = 0;
            for (int j = i; j <= n; j++)
            {
                lowest = min(lowest, a[j - i]);
                ans = max(ans, a[j] + (long long)x * i - lowest);
            }
            cout << ans << ' ';
        }
        cout << '\n';
    }
    return 0;
}
