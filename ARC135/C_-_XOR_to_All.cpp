#include <bits/stdc++.h>
using namespace std;

int a[300001], c[30];

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin >> n;
    long long now = 0;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
        now += a[i];
        for (int j = 0; j < 30; j++)
            c[j] += (a[i] >> j) & 1;
    }
    long long ans = now;
    for (int i = 1; i <= n; i++)
    {
        long long t = now;
        for (int j = 0, b = 1; j < 30; j++, b <<= 1)
            if (a[i] & b)
            {
                t += (long long)(n - c[j] * 2) * b;
            }
        ans = max(ans, t);
    }
    cout << ans;
    return 0;
}
