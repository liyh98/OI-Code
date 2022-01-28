#include <bits/stdc++.h>
using namespace std;

inline int get(int x)
{
    cout << "? " << x << '\n';
    cout.flush();
    int ret;
    cin >> ret;
    return ret;
}

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
        vector<int> ans(n + 1);
        for (int i = 1; i <= n; i++)
        {
            if (!ans[i])
            {
                while (get(i) != i)
                    ;
                int x = i;
                do
                {
                    ans[x] = get(i);
                    x = ans[x];
                } while (x != i);
            }
        }
        cout << "! ";
        for (int i = 1; i <= n; i++)
            cout << ans[i] << ' ';
        cout << '\n';
        cout.flush();
    }
    return 0;
}
