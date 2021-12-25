#include <bits/stdc++.h>
using namespace std;

long long a[1000001], f[1000001][2];

int main()
{
    int n;
    scanf("%d", &n);
    for (int i = 1; i <= n; i++)
    {
        scanf("%lld", &a[i]);
        a[i] += a[i - 1];
    }
    long long sum = a[n];
    if (sum == 1ll)
    {
        puts("-1");
        return 0;
    }
    long long ans = LLONG_MAX;
    for (long long i = 2; i * i <= sum; i++)
    {
        if (sum % i)
            continue;
        long long x = i;
        for (int j = 1; j <= n; j++)
        {
            f[j][0] = f[j][1] = LLONG_MAX;
            if (a[j] >= ((a[j - 1] - 1) / x + 1) * x)
                f[j][0] = min(f[j][0], f[j - 1][1] + (a[j] % x));
            f[j][0] = min(f[j][0], f[j - 1][0] + (a[j] % x));
            f[j][1] = min(f[j][1], f[j - 1][0] + ((x - (a[j] % x)) % x));
            f[j][1] = min(f[j][1], f[j - 1][1] + ((x - (a[j] % x)) % x));
        }
        ans = min(ans, min(f[n][0], f[n][1]));
        while (sum % i == 0)
            sum /= i;
    }
    if (sum > 1)
    {
        long long x = sum;
        for (int j = 1; j <= n; j++)
        {
            f[j][0] = f[j][1] = LLONG_MAX;
            if (a[j] >= ((a[j - 1] - 1) / x + 1) * x)
                f[j][0] = min(f[j][0], f[j - 1][1] + (a[j] % x));
            f[j][0] = min(f[j][0], f[j - 1][0] + (a[j] % x));
            f[j][1] = min(f[j][1], f[j - 1][0] + ((x - (a[j] % x)) % x));
            f[j][1] = min(f[j][1], f[j - 1][1] + ((x - (a[j] % x)) % x));
        }
        ans = min(ans, min(f[n][0], f[n][1]));
    }
    printf("%lld", ans);
    return 0;
}