#include <bits/stdc++.h>
using namespace std;

map<int, int> cnt;
int np, p[500];
bool v[1001];

int get(int x)
{
    int ret = 1;
    for (int i = 1; i <= np && p[i] * p[i] <= x; i++)
    {
        if (x % p[i] == 0)
        {
            bool cnt = 0;
            while (x % p[i] == 0)
                x /= p[i], cnt ^= 1;
            if (cnt)
                ret *= p[i];
        }
    }
    return ret * x;
}
void TC()
{
    int n, q;
    scanf("%d", &n);
    cnt.clear();
    for (int i = 1; i <= n; i++)
    {
        int x;
        scanf("%d", &x);
        cnt[get(x)]++;
    }
    int ans0 = 0, ans1 = 0;
    for (pair<int, int> p : cnt)
    {
        ans0 = max(ans0, p.second);
        if (p.first == 1 || p.second % 2 == 0)
            ans1 += p.second;
    }
    ans1 = max(ans1, ans0);
    scanf("%d", &q);
    while (q--)
    {
        long long x;
        scanf("%lld", &x);
        printf("%d\n", x ? ans1 : ans0);
    }
}
int main()
{
    for (int i = 2; i <= 1000; i++)
    {
        if (!v[i])
            p[++np] = i;
        for (int j = 1; j <= np && i * p[j] <= 1000; j++)
            v[i * p[j]] = 1;
    }
    int T;
    scanf("%d", &T);
    while (T--)
        TC();
    return 0;
}