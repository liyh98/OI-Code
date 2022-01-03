#include <bits/stdc++.h>
using namespace std;

int p[200001], ans[200001];
string s;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int T;
    cin >> T;
    while (T--)
    {
        int n;
        cin >> n;
        for (int i = 1; i <= n; i++)
            cin >> p[i];
        cin >> s;
        vector<tuple<char, int, int>> a;
        a.reserve(n);
        for (int i = 1; i <= n; i++)
        {
            a.emplace_back(s[i - 1], p[i], i);
        }
        sort(a.begin(), a.end());
        for (int i = 0; i < n; i++)
            ans[get<2>(a[i])] = i + 1;
        for (int i = 1; i <= n; i++)
            cout << ans[i] << ' ';
        cout << '\n';
    }
    return 0;
}
