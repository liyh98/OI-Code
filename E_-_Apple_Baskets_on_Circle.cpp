#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    ll k;
    cin >> n >> k;
    vector<ll> a(n);
    vector<pair<ll, int>> b(n);
    for (auto &x : a)
        cin >> x;
    for (int i = 0; i < n; i++)
    {
        b[i] = make_pair(a[i], i);
    }
    sort(b.begin(), b.end());
    ll now = 0;
    int more_than_now = 0;
    vector<bool> finished(n);
    for (int i = 0; i < n; i++)
    {
        if (k < (b[i].first - now) * (n - i))
        {
            now += k / (n - i);
            k -= k / (n - i) * (n - i);
            while (k)
            {
                if (!finished[more_than_now])
                    --k;
                ++more_than_now;
            }
            break;
        }
        else
        {
            k -= (b[i].first - now) * (n - i);
            now = b[i].first;
            finished[b[i].second] = true;
        }
    }
    for (int i = 0; i < n; i++)
    {
        cout << max(0ll, a[i] - now - (i < more_than_now)) << ' ';
    }
    return 0;
}
