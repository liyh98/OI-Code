#include <bits/stdc++.h>
using namespace std;

int c[300001], cnt[300001];
int main()
{
    int T;
    scanf("%d", &T);
    while (T--)
    {
        int n, m;
        scanf("%d%d", &n, &m);
        for (int i = 1; i <= m; i++)
            cnt[i] = 0;
        for (int i = 1; i <= n; i++)
        {
            int x;
            scanf("%d", &x);
            cnt[x]++;
        }
        for (int i = 1; i <= m; i++)
            scanf("%d", &c[i]);
        long long ans = 0;
        int now = 0;
        for (int i = m; i; i--)
        {
            int tar = max(0, min(i - now - 1, cnt[i]));
            cnt[i] -= tar;
            ans += (long long)c[i] * cnt[i];
            now += tar;
        }
        for (int i = 1; i <= now; i++)
            ans += c[i];
        printf("%lld\n", ans);
    }
    return 0;
}