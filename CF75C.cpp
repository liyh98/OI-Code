#include <bits/stdc++.h>
using namespace std;

int gcd(int x, int y)
{
    return x ? gcd(y % x, x) : y;
}

vector<int> cd;
int main()
{
    int a, b;
    scanf("%d%d", &a, &b);
    int g = gcd(a, b);
    for (int i = 1; i * i <= g; i++)
        if (g % i == 0)
            cd.push_back(i), cd.push_back(g / i);
    sort(cd.begin(), cd.end());
    int n;
    scanf("%d", &n);
    while (n--)
    {
        int l, h;
        scanf("%d%d", &l, &h);
        auto it = upper_bound(cd.begin(), cd.end(), h);
        int ans = *(--it);
        printf("%d\n", ans >= l ? ans : -1);
    }
    return 0;
}