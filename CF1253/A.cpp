#include <bits/stdc++.h>
using namespace std;

int a[100001], b[100001];
int main()
{
    int T;
    scanf("%d", &T);
    while (T--)
    {
        int n;
        scanf("%d", &n);
        for (int i = 1; i <= n; i++)
            scanf("%d", &a[i]);
        for (int i = 1; i <= n; i++)
            scanf("%d", &b[i]);
        int l;
        for (l = 1; l <= n; l++)
            if (a[l] != b[l])
                break;
        if (l > n)
        {
            puts("YES");
            continue;
        }
        if (a[l] > b[l])
        {
            puts("NO");
            continue;
        }
        for (l++; l <= n; l++)
            if (b[l] - a[l] != b[l - 1] - a[l - 1])
                break;
        if (l > n)
        {
            puts("YES");
            continue;
        }
        for (; l <= n; l++)
            if (b[l] != a[l])
                break;
        puts(l > n ? "YES" : "NO");
    }
    return 0;
}