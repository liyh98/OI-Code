#include <bits/stdc++.h>
using namespace std;

int n, tree[100001];

inline void update(int x)
{
    for (; x; x -= x & -x)
        tree[x]++;
}

inline int get(int x)
{
    int ret = 0;
    for (; x <= n; x += x & -x)
        ret += tree[x];
    return ret;
}
int main()
{
    int T;
    scanf("%d", &T);
    for (int i = 1; i <= T; i++)
    {
        memset(tree, 0, sizeof tree);
        printf("Case #%d:", i);
        int ans = 0;
        scanf("%d", &n);
        for (int j = 1; j <= n; j++)
        {
            int x;
            scanf("%d", &x);
            update(min(x, n));
            while (get(ans + 1) >= ans + 1)
                ans++;
            printf(" %d", ans);
        }
        puts("");
    }
    return 0;
}