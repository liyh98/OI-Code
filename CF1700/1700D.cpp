#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll v[200001];

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++)
        cin >> v[i], v[i] += v[i - 1];
    ll sum = v[n];
    for (int i = 1; i <= n; i++)
    {
        v[i] = (v[i] - 1) / i + 1;
        v[i] = max(v[i], v[i - 1]);
    }
    for (int i = 1; i <= n; i++)
    {
        v[i] = max(v[i], (sum - 1) / i + 1);
        v[i] = -v[i];
        // cout << v[i] << ' ';
    }
    int q;
    cin >> q;
    while (q--)
    {
        long long t;
        cin >> t;
        int ans = lower_bound(v + 1, v + n + 1, -t) - v;
        cout << (ans == n + 1 ? -1 : ans) << '\n';
    }
    return 0;
}
