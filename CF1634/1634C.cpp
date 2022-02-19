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
        int n, k;
        cin >> n >> k;
        if (k == 1)
        {
            cout << "YES\n";
            for (int i = 1; i <= n; i++)
                cout << i << '\n';
        }
        else if (n & 1)
            cout << "NO\n";
        else
        {
            cout << "YES\n";
            for (int i = 0; i < n; i += 2)
            {
                int base = i * k;
                for (int j = 1; j <= k; j++)
                    cout << base + j * 2 - 1 << ' ';
                cout << '\n';
                for (int j = 1; j <= k; j++)
                    cout << base + j * 2 << ' ';
                cout << '\n';
            }
        }
    }
    return 0;
}
