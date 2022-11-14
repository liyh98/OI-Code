#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int n, m;
    cin >> n >> m;
    vector<int> x(n), y(n);
    vector<tuple<int, int, int>> e(m);
    for (auto &v : x)
        cin >> v;
    for (auto &v : y)
        cin >> v;
    ll ans = LLONG_MAX;
    for (auto &[z, a, b] : e)
    {
        cin >> a >> b >> z;
        --a;
        --b;
    }
    for (int i = 0; i < n; ++i)
    {
        e.emplace_back(x[i], i, n);
        e.emplace_back(y[i], i, n + 1);
    }
    sort(e.begin(), e.end());
    vector<int> fa(n + 2);
    function<int(int)> find = [&](int x) -> int
    {
        return x == fa[x] ? x : fa[x] = find(fa[x]);
    };
    for (int i = 0; i < n + 2; i++)
    {
        fa[i] = i;
    }
    int cnt = 0;
    ll now = 0;
    for (auto [z, a, b] : e)
    {
        a = find(a);
        b = find(b);
        if (a == b)
            continue;
        ++cnt;
        now += z;
        fa[b] = a;
    }
    if (cnt == n + 1)
        ans = min(ans, now);
    for (int i = 0; i < n + 2; i++)
    {
        fa[i] = i;
    }
    cnt = 0;
    now = 0;
    for (auto [z, a, b] : e)
    {
        a = find(a);
        b = find(b);
        if (a == b || a == n || b == n)
            continue;
        ++cnt;
        now += z;
        fa[b] = a;
    }
    if (cnt == n)
        ans = min(ans, now);
    for (int i = 0; i < n + 2; i++)
    {
        fa[i] = i;
    }
    cnt = 0;
    now = 0;
    for (auto [z, a, b] : e)
    {
        a = find(a);
        b = find(b);
        if (a == b || a == n + 1 || b == n + 1)
            continue;
        ++cnt;
        now += z;
        fa[b] = a;
    }
    if (cnt == n)
        ans = min(ans, now);
    for (int i = 0; i < n + 2; i++)
    {
        fa[i] = i;
    }
    cnt = 0;
    now = 0;
    for (auto [z, a, b] : e)
    {
        a = find(a);
        b = find(b);
        if (a == b || a == n || b == n || a == n + 1 || b == n + 1)
            continue;
        ++cnt;
        now += z;
        fa[b] = a;
    }
    if (cnt == n - 1)
        ans = min(ans, now);
    cout << ans << '\n';
    return 0;
}
