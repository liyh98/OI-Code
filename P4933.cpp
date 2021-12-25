#include <bits/stdc++.h>
using namespace std;

const int MOD = 998244353;
int a[1001];
map<int, int> f[1001];

int main()
{
    int n, ans = 0;
    scanf("%d", &n);
    for (int i = 1; i <= n; i++)
        scanf("%d", &a[i]);
    for (int i = 1; i <= n; i++)
    {
        int tot = 0;
        for (int j = 1; j < i; j++)
        {
            int t = f[j][a[i] - a[j]] + 1;
            f[i][a[i] - a[j]] = (f[i][a[i] - a[j]] + t) % MOD;
            tot = (tot + t) % MOD;
        }
        ans = (ans + tot + 1) % MOD;
    }
    printf("%d", ans);
    return 0;
}