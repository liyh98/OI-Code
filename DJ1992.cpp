#include <bits/stdc++.h>
using namespace std;

multiset<long long> s;

int main()
{
    int n, q;
    scanf("%d%d", &n, &q);
    for (int i = 1; i <= n; i++)
    {
        int x;
        scanf("%d", &x);
        s.insert(x);
    }
    long long d = 0;
    while (q--)
    {
        char c[2];
        int x;
        scanf("%s%d", c, &x);
        if (c[0] == 'A')
        {
            d += x;
            while (s.begin() != s.end() && *s.begin() <= d)
                s.erase(s.begin());
            if (s.empty()) break;
        }
        else
        {
            auto it = s.upper_bound(d);
            if (it == s.end())
                break;
            else
            {
                long long t = *it + x;
                s.erase(it);
                s.insert(t);
            }
        }
    }
    printf("%d", n - (int)s.size());
    return 0;
}