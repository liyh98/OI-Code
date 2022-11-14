#include <bits/stdc++.h>
using namespace std;

#define MOD 1000000007

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int n, p;
    cin >> n >> p;
    vector<int> a(n);
    for (int &x : a)
        cin >> x;
    sort(a.begin(), a.end());
    unordered_set<int> s;
    vector<int> f(p);
    for (int x : a)
    {
        int t = x;
        vector<int> bin;
        while (x)
            bin.push_back(x & 1), x >>= 1;
        reverse(bin.begin(), bin.end());
        int m = bin.size();
        vector<bool> r(m);
        for (int i = 0, now = 0; i < m; i++)
        {
            now = now << 1 | bin[i];
            if (s.find(now) != s.end())
                r[i] = 1;
            if (r[i])
            {
                if (i < m - 1 && bin[i + 1] == 1)
                    r[i + 1] = 1;
                if (i < m - 2 && bin[i + 1] == 0 && bin[i + 2] == 0)
                    r[i + 2] = 1;
            }
        }
        if (!r[m - 1])
        {
            s.insert(t);
            if (m - 1 < p)
                f[m - 1]++;
            // cout << m - 1 << '\n';
        }
    }
    int ans = 0;
    for (int i = 0; i < p; i++)
    {
        f[i] %= MOD;
        (ans += f[i]) %= MOD;
        if (i < p - 1)
            (f[i + 1] += f[i]) %= MOD;
        if (i < p - 2)
            (f[i + 2] += f[i]) %= MOD;
    }
    cout << ans;
    return 0;
}
