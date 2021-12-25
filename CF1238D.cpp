#include <bits/stdc++.h>
using namespace std;

char a[300002];
int lst[2];
int main()
{
    int n, now = 0;
    long long ans = 0;
    scanf("%d%s", &n, a + 1);
    lst[a[1] - 'A'] = 1;
    for (int i = 2; i <= n; i++)
    {
        if (i > 2 && lst[a[i] - 'A'] == i - 1)
            ans += i - 1 - (lst[1 - (a[i] - 'A')] > 0);
        else
            ans += lst[a[i] - 'A'];
        //printf("%lld\n", ans);
        lst[a[i] - 'A'] = i;
    }
    printf("%lld", ans);
    return 0;
}