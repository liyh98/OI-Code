#include <bits/stdc++.h>
using namespace std;

int fa[200002], largest[200002], nex[200002];

int find(int x)
{
    return x == fa[x] ? x : fa[x] = find(fa[x]);
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int n, q;
    cin >> n >> q;
    for (int i = 0; i <= n + 1; i++)
    {
        fa[i] = largest[i] = i;
        nex[i] = n + 1;
    }
    for (int i = 1; i <= q; i++)
    {
        int t;
        cin >> t;
        if (!t)
        {
            int l, r, x;
            cin >> l >> r >> x;
            if (!x)
            {
                int f = find(l - 1);
                for (int i = largest[f] + 1; i <= r; i = largest[f] + 1)
                {
                    int y = find(i);
                    fa[y] = f;
                    largest[f] = largest[y];
                    nex[f] = min(nex[f], nex[y]);
                }
            }
            else
            {
                int y = find(l - 1);
                nex[y] = min(nex[y], r);
            }
        }
        else
        {
            int j;
            cin >> j;
            if (find(j) == find(j - 1))
                cout << "NO\n";
            else if (find(nex[find(j - 1)]) == j)
                cout << "YES\n";
            else
                cout << "N/A\n";
        }
    }
    return 0;
}
