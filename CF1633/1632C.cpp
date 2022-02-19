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
        int a, b;
        cin >> a >> b;
        int ans = b - a;
        for (int i = a; i <= b * 2; i += i & -i)
            for (int j = b; j <= b * 2; j += j & -j)
            {
                ans = min(ans, i - a + 1 + (i | j) - b);
            }
        cout << ans << '\n';
    }
    return 0;
}
