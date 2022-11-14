#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
    while (t--)
    {
        int n, c;
        cin >> n >> c;
        vector<int> cnt(101);
        while (n--)
        {
            int x;
            cin >> x;
            cnt[x]++;
        }
        int ans = 0;
        for (int x : cnt)
            ans += min(x, c);
        cout << ans << '\n';
    }
    return 0;
}
