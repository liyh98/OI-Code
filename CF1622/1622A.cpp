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
        int a, b, c;
        cin >> a >> b >> c;
        if (a == b + c || b == a + c || c == a + b || (a == b && !(c & 1)) || (a == c && !(b & 1)) || (c == b && !(a & 1)))
            cout << "YES\n";
        else
            cout << "NO\n";
    }
    return 0;
}
