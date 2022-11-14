#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int T;
    cin >> T;
    while (T--)
    {
        long long n, m;
        cin >> n >> m;
        cout << (m + 1) * m / 2 + n * (n - 1) / 2 * m + n - 1 + (m - 1) * (n - 1) << '\n';
    }
    return 0;
}
