#include <bits/stdc++.h>
using namespace std;

#define mod 1000000007
long long ksm(long long base, long long expo)
{
    long long ret = 1;
    for (; expo; expo >>= 1)
    {
        if (expo & 1)
            (ret *= base) %= mod;
        (base *= base) %= mod;
    }
    return ret;
}
int main()
{
    int n, m;
    scanf("%d%d", &n, &m);
    printf("%lld", ksm(ksm(2, m) - 1, n));
    return 0;
}