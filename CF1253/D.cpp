#include <bits/stdc++.h>
using namespace std;

int fa[200001];

int find(int x)
{
    return fa[x] == x ? x : fa[x] = find(fa[x]);
}

int main()
{
    int n, m;
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; i++)
        fa[i] = i;
    while (m--)
    {
        int x, y;
        scanf("%d%d", &x, &y);
        x = find(x), y = find(y);
        if (x != y)
            fa[min(x, y)] = max(x, y);
    }
    int ans = 0;
    for (int i = 1; i <= n; i++)
    {
        int fi = find(i);
        for (int j = i + 1; j < fi; j++)
        {
            int fj = find(j);
            if (fj != fi)
            {
                ans++;
                fi = fa[min(fj, fi)] = max(fj, fi);
            }
        }
        i = fi;
    }
    printf("%d", ans);
    return 0;
}