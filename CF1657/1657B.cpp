#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int T;
    cin >> T;
    while (T--)
    {
        int n, B, x, y, now = 0;
        cin >> n >> B >> x >> y;
        long long ans = 0;
        for (int i = 1; i <= n; i++)
        {
            if (now + x <= B)
                now += x;
            else
                now -= y;
            ans += now;
        }
        cout << ans << '\n';
    }
    return 0;
}
