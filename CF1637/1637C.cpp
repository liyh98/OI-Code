#include <bits/stdc++.h>
using namespace std;

int a[100001];

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
        long long ans = 0;
        bool flag = 0;
        for (int i = 2; i < n; i++)
        {
            ans += (a[i] + 1) >> 1;
            flag |= ~a[i] & 1;
            flag |= (n > 3) & (a[i] > 1);
        }
        cout << (flag ? ans : -1) << '\n';
    }
    return 0;
}
