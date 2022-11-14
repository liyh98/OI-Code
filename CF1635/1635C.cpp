#include <bits/stdc++.h>
using namespace std;

int a[200001];

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
            cin >> a[i];
        vector<array<int, 3>> ans;
        bool flag = 0;
        if (a[n] < 0)
        {
            for (int i = 1; i < n; i++)
            {
                if (a[i] > a[i + 1])
                {
                    flag = 1;
                    break;
                }
            }
        }
        else
        {
            if (a[n - 1] > a[n])
            {
                flag = 1;
            }
            else
            {
                for (int i = 1; i <= n - 2; i++)
                    ans.push_back({i, n - 1, n});
            }
        }
        if (flag)
        {
            cout << "-1\n";
        }
        else
        {
            cout << ans.size() << '\n';
            for (auto &[a, b, c] : ans)
                cout << a << ' ' << b << ' ' << c << '\n';
        }
    }
    return 0;
}
