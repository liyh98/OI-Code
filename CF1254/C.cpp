#include <bits/stdc++.h>
using namespace std;

long long s[1001];
vector<pair<long long, int>> lhs, rhs;
int main()
{
    int n;
    scanf("%d", &n);
    int l = 2;
    for (int i = 3; i <= n; i++)
    {
        printf("2 1 %d %d\n", l, i);
        fflush(stdout);
        int ret;
        scanf("%d", &ret);
        if (ret > 0)
            l = i;
    }
    int f = 0;
    for (int i = 2; i <= n; i++)
    {
        if (i == l)
            continue;
        printf("1 1 %d %d\n", l, i);
        fflush(stdout);
        scanf("%lld", &s[i]);
        if (s[i] > s[f])
            f = i;
    }
    for (int i = 2; i <= n; i++)
    {
        if (i==l || i == f) continue;
        printf("2 1 %d %d\n", f, i);
        fflush(stdout);
        int ret;
        scanf("%d", &ret);
        if (ret > 0) rhs.emplace_back(s[i], i);
        else lhs.emplace_back(s[i],i);
    }
    sort(lhs.begin(),lhs.end());
    sort(rhs.begin(),rhs.end(),greater<>());
    printf("0 1 ");
    for (auto p : lhs) printf("%d ", p.second);
    printf("%d ", f);
    for (auto p : rhs) printf("%d ", p.second);
    printf("%d\n", l);
    fflush(stdout);
    return 0;
}