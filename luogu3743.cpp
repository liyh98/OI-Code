#include <stdio.h>
#include <limits.h>

#define MAXN 100001

using namespace std;

const double N_MIN = 1e-6;

int n, p, a[MAXN], b[MAXN], sum;

double mid, l, r = 1e10;

bool check(double m)
{
    double t = m * (double)p;
    for (int i = 1; i <= n; i++)
    {
        double k = b[i] - a[i] * m;
        if (t < -k && k < 0)
            return false;
        t += k;
    }
    return true;
}

int main()
{
    scanf("%d%d", &n, &p);
    for (int i = 1; i <= n; i++)
        scanf("%d%d", &a[i], &b[i]), sum += a[i];
    if (sum <= p)
    {
        printf("-1");
        return 0;
    }
    while (r - l >= N_MIN)
    {
        mid = (l + r) / 2.0;
        if (check(mid))
            l = mid;
        else
            r = mid;
    }
    printf("%.10lf", l);
    return 0;
}