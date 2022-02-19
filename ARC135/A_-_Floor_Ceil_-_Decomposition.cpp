#include <bits/stdc++.h>
using namespace std;

#define MOD 998244353

unordered_map<long long, int> f;

inline int get(long long x)
{
    if (x <= 4)
        return x;
    auto it = f.find(x);
    if (it != f.end())
        return it->second;
    int ret = (long long)get(x / 2) * get(x - x / 2) % MOD;
    f[x] = ret;
    return ret;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    long long x;
    cin >> x;
    cout << get(x);
    return 0;
}
