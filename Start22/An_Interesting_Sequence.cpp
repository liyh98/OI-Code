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
        int n, ans = 0;
        cin >> n;
        while (!(n & 1))
            n >>= 1, ans++;
        cout << ans << '\n';
    }
    return 0;
}
