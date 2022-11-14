#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int T;
    cin >> T;
    while (T--)
    {
        int n, m, k;
        cin >> n >> m;
        vector<pair<int, long long>> a, b;
        for (int i = 1; i <= n; i++)
        {
            int x;
            cin >> x;
            int mul = 1;
            while (x % m == 0)
            {
                x /= m;
                mul *= m;
            }
            if (!a.empty() && a.back().first == x)
                a.back().second += mul;
            else
                a.emplace_back(x, mul);
        }
        cin >> k;
        for (int i = 1; i <= k; i++)
        {
            int x;
            cin >> x;
            int mul = 1;
            while (x % m == 0)
            {
                x /= m;
                mul *= m;
            }
            if (!b.empty() && b.back().first == x)
                b.back().second += mul;
            else
                b.emplace_back(x, mul);
        }
        if (a.size() != b.size())
            puts("No");
        else
        {
            bool flag = 1;
            for (int i = 0; i < a.size(); i++)
            {
                if (a[i] != b[i])
                    flag = 0;
            }
            puts(flag ? "Yes" : "No");
        }
    }
    return 0;
}
