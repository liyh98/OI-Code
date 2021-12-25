#include <bits/stdc++.h>
using namespace std;

int a[100001];
int main()
{
    int t;
    scanf("%d", &t);
    while (t--)
    {
        int n, r;
        scanf("%d%d", &n, &r);
        for (int i = 1; i <= n; i++)
            scanf("%d", &a[i]);
        sort(a + 1, a + n + 1);
        n = unique(a + 1, a + n + 1) - a - 1;
        for (int i = 1; i <= n; i++)
        {
            if (r * i >= a[n - i])
            {
                printf("%d\n", i);
                break;
            }
        }
    }
    return 0;
}