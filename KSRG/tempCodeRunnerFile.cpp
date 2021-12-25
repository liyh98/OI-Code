#include <bits/stdc++.h>
using namespace std;

bool c[100001];
int ans[100001];
int main()
{
    int T;
    scanf("%d", &T);
    for (int i = 1; i <= T; i++)
    {
        int n, m, q;
        scanf("%d%d%d", &n, &m, &q);
        memset(c, 0, sizeof c);
        while (m--)
        {
            int x;
            scanf("%d", &x);
            c[x] = 1;
        }
        for (int j = 1; j <= n; j++)
        {
            ans[j] = 0;
            for (int k = j; k <= n; k += j)
                ans[j] += !c[k];
        }
        long long Ans = 0;
        while (q--)
        {
            int x;
            scanf("%d", &x);
            Ans += ans[x];
        }
        printf("Case #%d: %d\n", i, Ans);
    }
    return 0;
}