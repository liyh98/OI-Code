#include <cstdio>
#include <cmath>
#include <algorithm>
#include <cstring>

using namespace std;

const int N = 250005;

struct edge
{
    int x, y;
    double val;
} t[N];

int s, p, a[N], b[N], cnt, tot, fa[N];
double ans;

inline int sqr(int a)
{
    return a * a;
}

inline double dist(int i, int j)
{
    return sqrt(sqr(a[i] - a[j]) + sqr(b[i] - b[j]));
}

inline bool cmp(edge a, edge b)
{
    return a.val < b.val;
}

inline int find(int x)
{
    if (fa[x] == x)
        return x;
    return fa[x] = find(fa[x]);
}

int main()
{
    scanf("%d%d", &s, &p);
    for (int i = 1; i <= p; ++i)
    {
        scanf("%d%d", &a[i], &b[i]);
        for (int j = 1; j < i; ++j)
        {
            ++cnt;
            t[cnt].val = dist(i, j);
            t[cnt].x = i;
            t[cnt].y = j;
            printf("%d %d\n", i, j);
        }
    }
    for (int i = 1; i <= p; ++i)
        fa[i] = i;
    sort(t + 1, t + cnt + 1, cmp);
    for (int i = 1; i <= cnt; ++i)
    {
        int ancx = find(t[i].x), ancy = find(t[i].y);
        if (ancx != ancy)
        {
            fa[ancy] = ancx;
            ans = t[i].val;
            ++tot;
            if (tot == p - s)
            {
                printf("%.2lf\n", ans);
                return 0;
            }
        }
    }
    return 0;
}