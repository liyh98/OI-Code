#include <bits/stdc++.h>
using namespace std;

int a[200001];
long long s[200001];
int main()
{
    int n, m;
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; i++)
        scanf("%d", &a[i]);
    sort(a + 1, a + n + 1);
    for (int i = 1; i <= n; i++)
        s[i] = i <= m ? a[i] : s[i - m] + a[i];
    long long ans = 0;
    for (int i = 1; i <= n; i++)
    {
        ans += a[i];
        if (i > m)
            ans += s[i - m];
        printf("%lld ", ans);
    }
    return 0;
}