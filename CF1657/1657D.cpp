#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int n, C;
    cin >> n >> C;
    vector<bool> np(C + 1);
    vector<int> p;
    for (int i = 2; i <= C; i++)
    {
        if (!np[i])
            p.push_back(i);
        for (int &x : p)
        {
            if (i * x > C)
                break;
            np[i * x] = 1;
            if (i % x == 0)
                break;
        }
    }
    vector<ll> f(C + 1);
    for (int i = 1; i <= n; i++)
    {
        int c, d, h;
        cin >> c >> d >> h;
        f[c] = max(f[c], (long long)d * h);
    }
    for (int i = 1; i <= C; i++)
    {
        f[i] = max(f[i], f[i - 1]);
        for (int &j : p)
        {
            if (i * j > C)
                break;
            f[i * j] = max(f[i * j], f[i] * j);
        }
    }
    int m;
    cin >> m;
    for (int i = 1; i <= m; i++)
    {
        long long D, H;
        cin >> D >> H;
        int k = upper_bound(f.begin(), f.end(), D * H) - f.begin();
        cout << (k == C + 1 ? -1 : k) << ' ';
    }
    return 0;
}
