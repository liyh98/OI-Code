#include <bits/stdc++.h>
using namespace std;

int main()
{
    long long n, p, w, d, x, y;
    scanf("%lld%lld%lld%lld", &n, &p, &w, &d);
    for (y = 0; y < w && y * d <= p; y++)
    {
        x = p - y * d;
        if (x % w == 0 && x / w + y <= n)
        {
            x /= w;
            printf("%lld %lld %lld", x, y, n - x - y);
            return 0;
        }
    }
    puts("-1");
    return 0;
}