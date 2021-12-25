#include <bits/stdc++.h>
using namespace std;

unordered_set<int> p, v;
int ans[100001];
int main()
{
    int n, cnt = 0, d = 1;
    scanf("%d", &n);
    for (int i = 1; i <= n; i++)
    {
        int x;
        scanf("%d", &x);
        if (x < 0)
        {
            x = -x;
            if (!p.count(x))
            {
                puts("-1");
                return 0;
            }
            p.erase(x);
            cnt--;
            if (!cnt)
            {
                ans[d++] = i;
                v.clear();
            }
        }
        else
        {
            if (v.count(x))
            {
                puts("-1");
                return 0;
            }
            p.insert(x);
            v.insert(x);
            cnt++;
        }
    }
    if (cnt)
    {
        puts("-1");
        return 0;
    }

    printf("%d\n", --d);
    for (int i = 1; i <= d; i++)
        printf("%d ", ans[i] - ans[i - 1]);
    return 0;
}