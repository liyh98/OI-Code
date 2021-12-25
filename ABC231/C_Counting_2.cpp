#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n, q;
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n >> q;
    vector<int> a(n);
    for (int &x : a)
        cin >> x;
    sort(a.begin(), a.end(), greater<>());
    vector<pair<int, int>> query(q);
    vector<int> ans(q);
    for (int i = 0; i < q; i++)
    {
        cin >> query[i].first;
        query[i].second = i;
    }
    sort(query.begin(), query.end(), greater<>());
    int i = 0;
    for (auto &p : query)
    {
        while (i < n && a[i] >= p.first)
            ++i;
        ans[p.second] = i;
    }
    for (int &x : ans)
        cout << x << endl;
}