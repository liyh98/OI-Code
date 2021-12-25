#include <bits/stdc++.h>
using namespace std;

long long a[21], b[21], hb[60000];
pair<long long, long long> s1[60000], s2[60000];
int tree[60001], lim;
inline int pow(int base, int expo)
{
    int ret = 1;
    while (expo--)
        ret *= base;
    return ret;
}

inline void update(int x)
{
    for (; x <= lim; x += x & -x)
        tree[x]++;
}

inline int get(int x)
{
    int ret = 0;
    for (; x; x -= x & -x)
        ret += tree[x];
    return ret;
}

int main()
{
    int T;
    scanf("%d", &T);
    for (int i = 1; i <= T; i++)
    {
        int n;
        long long h;
        scanf("%d%lld", &n, &h);
        for (int j = 1; j <= n; j++)
            scanf("%lld", &a[j]);
        for (int j = 1; j <= n; j++)
            scanf("%lld", &b[j]);
        int mid = n >> 1, rst = n - mid, lir = pow(3, rst);
        lim = pow(3, mid);
        for (int j = 0; j < lim; j++)
        {
            long long sa = 0, sb = 0;
            for (int k = 0; k < mid; k++)
            {
                int state = (j / pow(3, k)) % 3;
                if (state != 1)
                    sa += a[k + 1];
                if (state)
                    sb += b[k + 1];
            }
            s1[j] = make_pair(sa, sb);
            hb[j] = sb;
            //printf("%d %d\n", sa[j], sb[j]);
        }
        for (int j = 0; j < lir; j++)
        {
            long long sa = 0, sb = 0;
            for (int k = 0; k < rst; k++)
            {
                int state = (j / pow(3, k)) % 3;
                if (state != 1)
                    sa += a[mid + k + 1];
                if (state)
                    sb += b[mid + k + 1];
            }
            s2[j] = make_pair(sa, sb);
        }
        sort(s1, s1 + lim);
        sort(hb, hb + lim);
        sort(s2, s2 + lir);
        int k = lim - 1;
        long long ans = 0;
        memset(tree, 0, sizeof tree);
        for (int j = 0; j < lir; j++)
        {
            while (k >= 0 && s1[k].first + s2[j].first >= h)
            {
                update(lim - (lower_bound(hb, hb + lim, s1[k].second) - hb));
                k--;
            }
            ans += get(lim - (lower_bound(hb, hb + lim, h - s2[j].second) - hb));
        }
        printf("Case #%d: %lld\n", i, ans);
    }
    return 0;
}