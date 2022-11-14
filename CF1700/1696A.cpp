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
        int n, z;
        cin >> n >> z;
        int ans = 0;
        for (int i = 1; i <= n; i++)
        {
            int x;
            cin >> x;
            ans = max(ans, x | z);
        }
        cout << ans << '\n';
    }
    return 0;
}
