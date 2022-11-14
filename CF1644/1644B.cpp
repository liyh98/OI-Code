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
        for (int i = 1; i <= n; i++)
        {
            cout << i << ' ';
            for (int j = n; j; j--)
                if (i != j)
                    cout << j << ' ';
            cout << '\n';
        }
    }
    return 0;
}
