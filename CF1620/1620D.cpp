#include <bits/stdc++.h>
using namespace std;

int a[101];
vector<vector<int>> small_changes{{}, {1}, {2}, {1, 2}, {2, 2}};

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
        {
            cin >> a[i];
        }
        int ans = 1000'000'000;
        for (auto &changes : small_changes)
        {
            int tans = 0;
            for (int i = 1; i <= n; i++)
            {
                int mi = 1000'000'000;
                for (int j = 0; j < (1 << changes.size()); j++)
                {
                    int t = a[i];
                    for (int k = 0; k < changes.size(); k++)
                    {
                        if (j & (1 << k))
                            t -= changes[k];
                    }
                    if (t >= 0 && t % 3 == 0)
                        mi = min(mi, t / 3);
                }
                tans = max(tans, mi);
            }
            ans = min(ans, tans + (int)changes.size());
        }
        cout << ans << '\n';
    }
    return 0;
}
