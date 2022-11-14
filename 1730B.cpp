#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

inline void work()
{
    int n;
    cin >> n;
    vector<int> l(n), r(n);
    vector<pair<int, int>> a(n);
    for (auto &[x, t] : a)
    {
        cin >> x;
    }
    for (auto &[x, t] : a)
    {
        cin >> t;
    }
    if (n == 1)
    {
        cout << a[0].first << '\n';
        return;
    }
    sort(a.begin(), a.end());
    l[0] = a[0].first - a[0].second;
    for (int i = 1; i < n; ++i)
    {
        l[i] = min(l[i - 1], a[i].first - a[i].second);
    }
    r[n - 1] = a[n - 1].first + a[n - 1].second;
    for (int i = n - 2; i >= 0; --i)
    {
        r[i] = max(r[i + 1], a[i].first + a[i].second);
    }
    int best = INT_MAX, ans = -1;
    for (int i = 0; i < n - 1; ++i)
    {
        int bestPos = l[i] + r[i + 1];
        bestPos = max((a[i].first << 1), min((a[i + 1].first << 1), bestPos));
        if (best > max((r[i + 1] << 1) - bestPos, bestPos - (l[i] << 1)))
        {
            best = max((r[i + 1] << 1) - bestPos, bestPos - (l[i] << 1));
            ans = bestPos;
        }
    }
    cout << ans / 2;
    if (ans & 1)
    {
        cout << ".5";
    }
    cout << '\n';
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
    while (t--)
    {
        work();
    }
    return 0;
}
