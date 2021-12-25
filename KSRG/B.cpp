#include <bits/stdc++.h>
using namespace std;

long long a[1001], f[50][2];
int main()
{
    int T;
    scanf("%d", &T);
    for (int i = 1; i <= T; i++)
    {
        int n;
        long long m, mi = 0;
        scanf("%d%lld", &n, &m);
        for (int j = 1; j <= n; j++)
            scanf("%lld", &a[j]);
        for (int j = 0; j < 50; j++)
        {
            long long base = 1ll << j;
            int cnt = 0;
            for (int k = 1; k <= n; k++)
            {
                if (a[k] & base)
                    cnt++;
            }
            f[j][0] = base * cnt;
            f[j][1] = base * (n - cnt);
            mi += min(f[j][0], f[j][1]);
        }
        if (mi > m)
        {
            printf("Case #%d: -1\n", i);
            continue;
        }
        long long ans = 0;
        for (int j = 49; j >= 0; j--)
        {
            mi -= min(f[j][0], f[j][1]);
            if (f[j][1] + mi <= m)
                ans |= 1ll << j, mi += f[j][1];
            else
                mi += f[j][0];
        }
        printf("Case #%d: %lld\n", i, ans);
    }
    return 0;
}