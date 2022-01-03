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
        vector<int> cnt(101);
        cin >> n;
        for (int i = 1; i <= n; i++)
        {
            int x;
            cin >> x;
            cnt[abs(x)]++;
        }
        int ans = min(1, cnt[0]);
        for (int i = 1; i <= 100; i++)
            ans += min(2, cnt[i]);
        cout << ans << '\n';
    }
    return 0;
}
