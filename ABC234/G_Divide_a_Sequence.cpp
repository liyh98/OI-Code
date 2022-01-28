#include <bits/stdc++.h>
using namespace std;

#define MOD 998244353

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin >> n;
    stack<pair<int, long long>> st1, st2;
    st1.emplace(0, 0);
    st2.emplace(INT_MAX, 0);
    long long now = 0, sx = 1;
    for (int i = 1; i <= n; i++)
    {
        int x;
        cin >> x;
        while (st1.top().first >= x)
        {
            int val;
            long long sv;
            tie(val, sv) = st1.top();
            st1.pop();
            (now += (sv - st1.top().second) * val) %= MOD;
        }
        (now -= (sx - st1.top().second) * x) %= MOD;
        st1.emplace(x, sx);
        while (st2.top().first <= x)
        {
            int val;
            long long sv;
            tie(val, sv) = st2.top();
            st2.pop();
            (now -= (sv - st2.top().second) * val) %= MOD;
        }
        (now += (sx - st2.top().second) * x) %= MOD;
        st2.emplace(x, sx);
        (sx += now) %= MOD;
    }
    cout << (now + MOD) % MOD;
    return 0;
}
