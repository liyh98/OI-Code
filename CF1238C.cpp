#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    scanf("%d", &t);
    while (t--)
    {
        int h, n, cnt = 0, x, pre = INT_MAX, ans = 0;
        scanf("%d%d%d", &h, &n, &h);
        for (int i = 1; i < n; i++)
        {
            scanf("%d", &x);
            if (x == pre - 1)
            {
                cnt++;
                pre--;
            }
            else
            {
                if (cnt & 1) ans++;
                cnt = 1;
                pre = x;
            }
        }
        if (cnt & 1 && pre != 1) ans++;
        printf("%d\n", ans);
    }
    return 0;
}