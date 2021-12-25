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
        int w, h, k;
        cin >> w >> h;
        long long l, r, ans = 0;
        cin >> k >> l;
        while (--k)
            cin >> r;
        ans = max(ans, (r - l) * h);
        cin >> k >> l;
        while (--k)
            cin >> r;
        ans = max(ans, (r - l) * h);
        cin >> k >> l;
        while (--k)
            cin >> r;
        ans = max(ans, (r - l) * w);
        cin >> k >> l;
        while (--k)
            cin >> r;
        ans = max(ans, (r - l) * w);
        cout << ans << '\n';
    }
    return 0;
}
