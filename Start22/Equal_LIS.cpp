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
        if (n == 2)
            cout << "NO\n";
        else if (n & 1)
        {
            cout << "YES\n";
            for (int i = n; i > (n >> 1) + 1; i--)
                cout << i << ' ';
            for (int i = 1; i <= n >> 1; i++)
                cout << i << ' ';
            cout << (n >> 1) + 1 << '\n';
        }
        else
        {
            cout << "YES\n";
            for (int i = 1; i < (n >> 1) - 1; i++)
                cout << i << ' ';
            cout << (n >> 1) << ' ' << (n >> 1) - 1 << ' ';
            for (int i = n; i > (n >> 1); i--)
                cout << i << ' ';
            cout << '\n';
        }
    }
    return 0;
}
