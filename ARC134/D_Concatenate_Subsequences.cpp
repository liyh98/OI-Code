#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin >> n;
    vector<tuple<int, int, int>> a(n), ans;
    for (auto &[f, id, s] : a)
        cin >> f;
    for (auto &[f, id, s] : a)
        cin >> s;
    for (int i = 0; i < n; i++)
        get<1>(a[i]) = i;
    sort(a.begin(), a.end());
    for (auto &[f, id, s] : a)
    {
        if (ans.empty())
        {
            ans.emplace_back(f, id, s);
        }
        else
        {
            auto &[lf, lid, ls] = ans.back();
            if (lid < id)
            {
                if (f >= s && get<2>(ans.front()) > s && f == get<0>(ans.front()))
                {
                    ans.clear();
                    ans.emplace_back(f, id, s);
                }
                else if (f < get<2>(ans.front()))
                    ans.emplace_back(f, id, s);
                else if (f == get<2>(ans.front()) && ans.size() > 1 && f < get<2>(ans[1]))
                    ans.emplace_back(f, id, s);
            }
        }
    }
    for (auto &[f, id, s] : ans)
        cout << f << ' ';
    for (auto &[f, id, s] : ans)
        cout << s << ' ';
    return 0;
}
