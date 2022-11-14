#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int n, q;
    cin >> n >> q;
    vector<vector<int>> a(n);
    for (int i = 0; i < n; i++)
    {
        int l;
        cin >> l;
        a[i].resize(l);
        for (auto &x : a[i])
            cin >> x;
    }
    while (q--)
    {
        int s, t;
        cin >> s >> t;
        cout << a[s - 1][t - 1] << '\n';
    }
    return 0;
}
