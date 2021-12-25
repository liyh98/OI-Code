#include <bits/stdc++.h>
using namespace std;
long long a[12][2000][81], ans, n, m, s[2000], t[2000], c, ss;
int main()
{
    scanf("%lld%lld", &n, &m);
    for (int i = 0; i < (1 << n); i++)
        if (!((i << 1) & i) && !((i >> 1) & i))
        {
            int l = i;
            c++;
            while (l != 0)
            {
                s[c] += l & 1;
                l >>= 1;
            }
            t[c] = i;
            a[1][c][s[c]] = 1;
        }
    for (int i = 2; i <= n; i++)
        for (int j = 1; j <= c; j++)
            for (int k = 1; k <= c; k++)
                if (!((t[j] << 1) & t[k]) && !((t[j] >> 1) & t[k]) && !(t[j] & t[k]))
                    for (int l = 0; l <= m; l++)
                        a[i][j][s[j] + l] += a[i - 1][k][l];
    for (int j = 1; j <= c; j++)
        ans += a[n][j][m];
    printf("%lld", ans);
    return 0;
}