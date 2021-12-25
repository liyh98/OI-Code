#include <bits/stdc++.h>
using namespace std;

vector<int> e[300001];
int ans = 0;

int dfs(int x, int pre)
{
    int cnt = 0, max1 = 0, max2 = 0;
    for (int nex : e[x])
    {
        if (nex != pre)
        {
            cnt++;
            int ret = dfs(nex, x);
            if (ret > max1)
                max2 = max1, max1 = ret;
            else if (ret > max2)
                max2 = ret;
        }
    }
    ans = max(ans, 1 + max1 + max2 + max((pre != 0) + cnt - 2, 0));
    return 1 + max1 + max(cnt - 1, 0);
}
int main()
{
    int q;
    scanf("%d", &q);
    while (q--)
    {
        int n;
        scanf("%d", &n);
        ans = 0;
        for (int i = 1; i <= n; i++)
            e[i].clear();
        for (int i = 1; i < n; i++)
        {
            int x, y;
            scanf("%d%d", &x, &y);
            e[x].push_back(y);
            e[y].push_back(x);
        }
        dfs(1, 0);
        printf("%d\n", ans);
    }
    return 0;
}