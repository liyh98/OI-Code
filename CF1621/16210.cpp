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
        if (k > (n + 1) >> 1)
            cout << "-1\n";
        else
        {
            for (int i = 1; i <= n; i++)
            {
                for (int j = 1; j <= n; j++)
                {
                    if (i == j && i & 1 && i <= k << 1)
                        cout << 'R';
                    else
                        cout << '.';
                }
                cout << '\n';
            }
        }
    }
    return 0;
}
