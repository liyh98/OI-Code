#include <bits/stdc++.h>
using namespace std;

unordered_map<int, int> hs;
int cnt;
vector<vector<int>> l;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int n, q;
    cin >> n >> q;
    for (int i = 1; i <= n; i++)
    {
        int x;
        cin >> x;
        if (hs.find(x) == hs.end())
            hs[x] = cnt++, l.resize(cnt);
        l[hs[x]].push_back(i);
    }
    while (q--)
    {
        int x, k;
        cin >> x >> k;
        if (hs.find(x) == hs.end())
        {
            cout << "-1\n";
            continue;
        }
        if (l[hs[x]].size() < k)
        {
            cout << "-1\n";
            continue;
        }
        cout << l[hs[x]][k - 1] << '\n';
    }
    return 0;
}
