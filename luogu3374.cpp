#include <bits/stdc++.h>
using namespace std;

long long s[500001];
int n;

inline void update(int x, int v)
{
    for (; x <= n; x += x & -x)
        s[x] += v;
}

inline long long get(int x)
{
    long long ret = 0;
    for (; x; x -= x & -x) ret += s[x];
    return ret;
}
int main()
{
    int m;
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; i++)
    {
        int x;
        scanf("%d", &x);
        update(i, x);
    }
    for (int i = 1; i <= m; i++)
    {
        int op, l, r;
        scanf("%d%d%d", &op, &l, &r);
        if (op == 1)
            update(l, r);
        else
            printf("%lld\n", get(r) - get(l - 1));
    }
    return 0;
}