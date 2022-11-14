#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int n, m, k;
    cin >> n >> m >> k;
    vector<long long> dis(n, LLONG_MAX >> 1);
    vector<tuple<int, int, int>> e(m);
    dis[0] = 0;
    for (auto &[a, b, c] : e)
        cin >> a >> b >> c;
    while (k--)
    {
        int x;
        cin >> x;
        auto &[a, b, c] = e[x - 1];
        dis[b - 1] = min(dis[b - 1], dis[a - 1] + c);
    }
    cout << (dis[n - 1] == LLONG_MAX >> 1 ? -1 : dis[n - 1]) << '\n';
    return 0;
}
