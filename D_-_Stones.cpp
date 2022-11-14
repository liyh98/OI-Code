#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int n, k;
    cin >> n >> k;
    vector<int> a(k);
    for (auto &x : a)
        cin >> x;
    vector<int> f(n + 1);
    for (int i = 1; i <= n; ++i)
    {
        for (int j : a)
        {
            if (i < j)
                break;
            f[i] = max(f[i], i - f[i - j]);
        }
    }
    cout << f[n];
    return 0;
}
