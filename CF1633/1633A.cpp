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
        cin >> n;
        int x = n % 10;
        if (x >= n % 7)
            n -= n % 7;
        else
            n += 7 - (n % 7);
        cout << n << '\n';
    }
    return 0;
}
