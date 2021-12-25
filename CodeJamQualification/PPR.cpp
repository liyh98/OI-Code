#include <bits/stdc++.h>
using namespace std;

pair<pair<int, int>, int> a[1001];
bool ans[1001];
inline void TC()
{
    int n;
    scanf("%d", &n);
    for (int i = 1; i <= n; i++)
        scanf("%d%d", &a[i].first.first, &a[i].first.second), a[i].second = i;
    sort(a + 1, a + n + 1);
    int c = 0, j = 0;
    for (int i = 1; i <= n; i++)
    {
        if (c <= a[i].first.first)
            ans[a[i].second] = 0, c = a[i].first.second;
        else if (j <= a[i].first.first)
            ans[a[i].second] = 1, j = a[i].first.second;
        else
        {
            puts("IMPOSSIBLE");
            return;
        }
    }
    for (int i = 1; i <= n; i++) putchar(ans[i] ? 'J' : 'C');
    putchar('\n');
}

int main()
{
    int T;
    scanf("%d", &T);
    for (int i = 1; i <= T; i++)
    {
        printf("Case #%d: ", i);
        TC();
    }
    return 0;
}