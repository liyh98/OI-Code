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
        int t1, t2, r1, r2;
        cin >> t1 >> t2 >> r1 >> r2;
        puts(t1 * t1 * r2 * r2 * r2 == t2 * t2 * r1 * r1 * r1 ? "Yes" : "No");
    }
    return 0;
}
