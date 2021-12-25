#include <bits/stdc++.h>
using namespace std;

int a[100001];

int main()
{
    int T;
    scanf("%d", &T);
    while (T--)
    {
        int n, ans = 0;
        scanf("%d", &n);
        for (int i = 1; i <= n; i++)
            scanf("%d", &a[i]);
        sort(a + 1, a + n + 1);
        for (int i = n; i; i--)
        {
            if (i >= a[i])
            {
                ans = i;
                break;
            }
        }
        printf("%d\n", ans + 1);
    }
}