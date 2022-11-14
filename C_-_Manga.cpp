#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin >> n;
    vector<bool> v(n + 1);
    for (int i = 0; i < n; ++i)
    {
        int x;
        cin >> x;
        if (x <= n)
            v[x] = true;
    }
    int ans = 0, used = 0;
    while (ans < n)
    {
        int use = 2 - v[ans + 1];
        if (used + use > n)
            break;
        used += use;
        ++ans;
    }
    cout << ans << '\n';
    return 0;
}
