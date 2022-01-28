#include <bits/stdc++.h>
using namespace std;

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
        vector<pair<int, int>> monsters(n);
        for (auto &[k, h] : monsters)
            cin >> k;
        for (auto &[k, h] : monsters)
            cin >> h;
        vector<pair<int, int>> st;
        long long ans = 0;
        for (auto &[k, h] : monsters)
        {

            while (!st.empty() && k - h < st.back().first - st.back().second)
                st.pop_back();
            if (!st.empty() && k - h < st.back().first)
            {
                st.back().second += k - st.back().first;
                st.back().first = k;
            }
            else
            {
                st.emplace_back(k, h);
            }
        }
        for (auto &[k, h] : st)
            ans += (long long)(h + 1) * h >> 1;
        cout << ans << '\n';
    }
    return 0;
}
