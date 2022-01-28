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
        if (n == 4 && k == 3)
        {
            cout << "-1\n";
            continue;
        }
        if (k == n - 1)
        {
            cout << n - 2 << ' ' << n - 1 << '\n';
            cout << 1 << ' ' << n - 3 << '\n';
            cout << 2 << ' ' << 0 << '\n';
            for (int i = 3; i < (n >> 1); i++)
                cout << i << ' ' << n - 1 - i << '\n';
            continue;
        }
        cout << k << ' ' << n - 1 << '\n';
        for (int i = 1; i < (n >> 1); i++)
        {
            int fi = i, se = n - 1 - i;
            fi *= (fi != k);
            se *= (se != k);
            cout << fi << ' ' << se << '\n';
        }
    }
    return 0;
}
