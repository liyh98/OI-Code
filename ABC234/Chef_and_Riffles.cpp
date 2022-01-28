#include <bits/stdc++.h>
using namespace std;

int nex[300001], ans[300001];
bool vis[300001];
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int T;
    cin >> T;
    while (T--)
    {
        int n, k;
        cin >> n >> k;
        for (int i = 1; i < n; i += 2)
            nex[i] = (i + 1) >> 1;
        for (int i = 2; i <= n; i += 2)
            nex[i] = (i + n) >> 1;
        memset(vis, 0, sizeof vis);
        for (int i = 1; i <= n; i++)
        {
            if (!vis[i])
            {
                vector<int> e;
                int x = i;
                while (!vis[x])
                {
                    vis[x] = 1;
                    e.push_back(x);
                    x = nex[x];
                }
                int m = e.size();
                for (int i = 0; i < m; i++)
                    ans[e[(i + k) % m]] = e[i];
            }
        }
        for (int i = 1; i <= n; i++)
            cout << ans[i] << ' ';
        cout << '\n';
    }
    return 0;
}
