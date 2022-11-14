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
        int x, y;
        cin >> x >> y;
        int s = x * x + y * y;
        int r = sqrt(s);
        cout << (s ? (r * r == s ? 1 : 2) : 0) << '\n';
    }
    return 0;
}
