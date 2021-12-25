#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    long long x, y;
    cin >> n >> x >> y;
    vector<int> a(n), b(n);
    for (int &x : a)
        cin >> x;
    for (int &x : b)
        cin >> x;
    vector<long long> f(1 << n, LLONG_MAX);
    f[0] = 0;
    for (int i = 0; i < (1 << n); i++)
    {
        int pos = __builtin_popcount(i);
        int c = 0;
        for (int j = 0; j < n; j++)
        {
            if (!((i >> j) & 1))
            {
                f[i | (1 << j)] = min(f[i | (1 << j)], f[i] + x * abs(a[j] - b[pos]) + y * c);
                c++;
            }
        }
    }
    cout << f.back();
    return 0;
}
