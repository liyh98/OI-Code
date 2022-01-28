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
        string x;
        cin >> x;
        int n = x.length();
        int p1 = 0, p2 = 0;
        for (int i = 1; i < n; i++)
        {
            if (x[i - 1] - '0' + x[i] - '0' >= 10)
                p2 = i;
            else if (!p1)
                p1 = i;
        }
        if (!p2)
            p2 = p1;
        cout << x.substr(0, p2 - 1);
        cout << x[p2 - 1] - '0' + x[p2] - '0';
        cout << x.substr(p2 + 1, n - p2 - 1) << '\n';
    }
    return 0;
}
