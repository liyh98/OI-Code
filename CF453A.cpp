#include <bits/stdc++.h>
using namespace std;

long double ksm(long double base, int expo)
{
    long double ret = 1;
    for (; expo; expo >>= 1, base *= base)
        if (expo & 1)
            ret *= base;
    return ret;
}
int main()
{
    int m, n;
    scanf("%d%d", &m, &n);
    long double ans = 0, lst = 1, now = 0;
    for (int i = m; i; i--)
    {
        now = ksm((long double)(i - 1) / m, n);
        ans += (lst - now) * i;
        lst = now;
    }
    printf("%.10Lf", ans);
    return 0;
}