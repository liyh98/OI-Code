#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int a, b, c, d, k;
        cin >> a >> b >> c >> d >> k;
        if ((a - 1) / c + (b - 1) / d + 2 > k) puts("-1");
        else cout << (a - 1) / c + 1 << ' ' << (b - 1) / d + 1 << endl;
    }
    return 0;
}