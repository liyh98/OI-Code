#include <bits/stdc++.h>
using namespace std;

int n, x[100], s[100], f[100][100];

int dp(int l, int r)
{
    int &ret = f[l][r];
    if (ret != -1)
        return ret;
    ret = INT_MAX;
    if (l)
        ret = min(ret, max(x[r] - x[l] - s[l], 0));
    if (r <= n)
        ret = min(ret, max(x[r] - x[l] - s[r], 0));
    for (int i = l + 1; i < r; i++)
        ret = min(ret, max(max(x[r] - x[i] - s[r] - s[i], x[i] - x[l] -s[l] - s[i]), 0));
    for (int i = l + 1; i < r; i++)
        ret = min(ret, dp(l, i)+dp(i,r));
    return ret;
}

int main()
{
    int m;
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; i++)
        scanf("%d%d", &x[i], &s[i]);
    x[0] = 1;
    x[n + 1] = m;
    memset(f, -1, sizeof f);
    printf("%d", dp(0, n + 1));
    return 0;
}