#include <bits/stdc++.h>
using namespace std;

int d[200001];

#define loc(r) (((r) % n))
int main()
{
    int n;
    long long x;
    scanf("%d%lld", &n, &x);
    for (int i = 1; i <= n; i++)
        scanf("%d", &d[i]);
    d[0] = d[n];
    int l = 1, r = 0;
    long long now = 0, sum = 0, ans = 0;
    while (r < n && now + d[r + 1] <= x)
        now += d[++r], sum += (long long)(1 + d[r]) * d[r] >> 1;
    ans = sum + ((long long)(1 + x - now) * (x - now) >> 1);
    //printf("%lld %lld %lld %lld\n", x - now, now, sum, ans);
    for (r++; r <= n + n; r++)
    {
        now += d[loc(r)];
        sum += (long long)(1 + d[loc(r)]) * d[loc(r)] >> 1;
        while (now > x)
            now -= d[loc(l)], sum -= (long long)(1 + d[loc(l)]) * d[loc(l)] >> 1, l++;
        if (l > n + 1 && r > n) break;
        //printf("%d %d %lld %lld\n", l, r, now, sum);
        if (d[loc(l - 1)] >= x - now)
            ans = max(ans, sum + ((long long)(d[loc(l - 1)] + d[loc(l - 1)] - x + now + 1) * (x - now) >> 1));
        else
            ans = max(ans, sum + ((long long)(1 + x - now) * (x - now) >> 1) * (r < n + n));
    }
    printf("%lld", ans);
    return 0;
}