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
        int n, d;
        cin >> n >> d;
        int now = 1;
        for (int i = 1; i <= d; i++)
        {
            now *= (2 + (i > 10));
            if (now >= n)
                break;
        }
        cout << min(now, n) << '\n';
    }
    return 0;
}
