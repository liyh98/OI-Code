#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int x, y, z, ans;
    cin >> x >> y >> z;
    if (x * y < 0)
        ans = abs(x);
    else if (abs(x) < abs(y))
        ans = abs(x);
    else if (y * z < 0)
        ans = abs(x) + (abs(z) << 1);
    else if (abs(z) < abs(y))
        ans = abs(x);
    else
        ans = -1;
    cout << ans << '\n';

    return 0;
}
