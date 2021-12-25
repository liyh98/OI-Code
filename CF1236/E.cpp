#include <bits/stdc++.h>
using namespace std;

int a[100001];
int fa[200002], h[200001], rf[200001];

int find(int x)
{
    return x == fa[x] ? x : fa[x] = find(fa[x]);
}
int main()
{
    int n, m;
    scanf("%d%d", &n, &m);
    if (n==1) {
        putchar('0');
        return 0;
    }
    for (int i = 1; i <= m; i++)
        scanf("%d", &a[i]);
    for (int i = 1; i <= n; i++)
        rf[i] = i, h[i] = i;
    for (int i = 1; i <= n + m + 1; i++)
        fa[i] = i;
    for (int i = 1; i <= m; i++)
    {
        if (h[i])
        {
            if (!h[i + 1])
                rf[h[i]] = i + 1, h[i + 1] = h[i], h[i] = 0;
            else
                fa[h[i]] = h[i + 1], rf[h[i]] = 0, h[i] = 0;
        }
        int pos = i + a[i];
        if (h[pos])
        {
            if (!h[pos + 1])
                rf[h[pos]] = pos + 1, h[pos + 1] = h[pos], h[pos] = 0;
            else
                fa[h[pos]] = h[pos + 1], rf[h[pos]] = 0, h[pos] = 0;
        }
    }
    if (h[m + 1])
    {
        if (!h[m + 1 + 1])
            rf[h[m + 1]] = m + 1 + 1, h[m + 1 + 1] = h[m + 1], h[m + 1] = 0;
        else
            fa[h[m + 1]] = h[m + 1 + 1], rf[h[m + 1]] = 0, h[m + 1] = 0;
    }
    long long ans = 0;
    for (int i = 1; i <= n; i++)
        if (rf[find(i)] - m - 1 > 0 && rf[find(i)] - m - 1 <= i)
            ans += i - (rf[find(i)] - m - 1) + 1;
    memset(rf, 0, sizeof rf);
    memset(h, 0, sizeof h);
    for (int i = 1; i <= m; i++)
        a[i] = n + 1 - a[i];
    for (int i = 1; i <= n; i++)
        rf[i] = i, h[i] = i;
    for (int i = 1; i <= n + m + 1; i++)
        fa[i] = i;
    for (int i = 1; i <= m; i++)
    {
        if (h[i])
        {
            if (!h[i + 1])
                rf[h[i]] = i + 1, h[i + 1] = h[i], h[i] = 0;
            else
                fa[h[i]] = h[i + 1], rf[h[i]] = 0, h[i] = 0;
        }
        int pos = i + a[i];
        if (h[pos])
        {
            if (!h[pos + 1])
                rf[h[pos]] = pos + 1, h[pos + 1] = h[pos], h[pos] = 0;
            else
                fa[h[pos]] = h[pos + 1], rf[h[pos]] = 0, h[pos] = 0;
        }
    }
    if (h[m + 1])
    {
        if (!h[m + 1 + 1])
            rf[h[m + 1]] = m + 1 + 1, h[m + 1 + 1] = h[m + 1], h[m + 1] = 0;
        else
            fa[h[m + 1]] = h[m + 1 + 1], rf[h[m + 1]] = 0, h[m + 1] = 0;
    }
    for (int i = 1; i <= n; i++)
        if (rf[find(i)] - m - 1 > 0 && rf[find(i)] - m - 1 <= i)
            ans += i - (rf[find(i)] - m - 1);
    cout << ans;
    return 0;
}