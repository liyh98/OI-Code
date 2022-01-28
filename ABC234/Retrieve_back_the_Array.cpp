#include <bits/stdc++.h>
using namespace std;

int ans[100001];
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
        for (int i = 1; i < n; i++)
            ans[i] = i, x ^= i;
        if (x == 1)
        {
            ans[1] = (1 << 17) | 2;
            ans[2] = 1 << 18;
            ans[n] = (1 << 17) | (1 << 18);
        }
        else if (x && x < n)
        {
            ans[1] = (1 << 17) | 1;
            ans[x] = 1 << 18;
            ans[n] = (1 << 17) | (1 << 18);
        }
        else if (x > 500000)
        {
            ans[1] |= 1 << 17;
            ans[n] = x ^ (1 << 17);
        }
        else
            ans[n] = x;
        for (int i = 1; i <= n; i++)
            cout << ans[i] << ' ';
        cout << '\n';
    }
    return 0;
}
