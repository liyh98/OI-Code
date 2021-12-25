#include <bits/stdc++.h>
using namespace std;

long long gcd(int x, int y)
{
    return x ? gcd(y % x, x) : y;
}

void exgcd(long long a, long long b, long long &x, long long &y)
{
    if (b == 0)
    {
        x = 1;
        y = 0;
        return;
    }
    exgcd(b, a % b, y, x);
    y -= a / b * x;
}

int main()
{
    long long n, p, w, d, x, y;
    scanf("%lld%lld%lld%lld", &n, &p, &w, &d);
    long long g = gcd(w, d);
    if (p % g)
    {
        puts("-1");
        return 0;
    }
    p /= g, w /= g, d /= g;
    exgcd(w, d, x, y);
    if (x < 0)
        x += d * ((-x - 1) / d + 1), y -= w * ((-x - 1) / d + 1);
    if (y < 0)
        y += w * ((-y - 1) / w + 1), x -= d * ((-y - 1) / w + 1);
    x *= p, y *= p;
    long long delta = min((n - x) / d, y / w);
    x += delta * d, y -= delta * w;
    if (x < 0 || y < 0 || x + y > n)
        puts("-1");
    else
        printf("%lld %lld %lld\n", x, y, n - x - y);
    return 0;
}