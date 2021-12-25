#include <bits/stdc++.h>
using namespace std;

int s[2000005];

char read()
{
    char c = getchar();
    while (c != '.' && c != '#')
        c = getchar();
    return c;
}

int main()
{
    int r, c;
    long long ans = 0;
    scanf("%d%d", &r, &c);
    for (int i = 1; i <= r; i++)
        for (int j = 1; j <= c; j++)
            s[(i - 1) * c + j - 1] = read();
    for (int i = 1; i <= r; i++)
    {
        for (int j = 1; j <= c; )
        {
            int cnt = 0;
            while (j <= c && s[(i - 1) * c + (j++) - 1] == '.')
                cnt++;
            ans += (long long)cnt * (cnt - 1);
        }
    }
    for (int i = 1; i <= c; i++)
    {
        for (int j = 1; j <= r; )
        {
            int cnt = 0;
            while (j <= r && s[((j++) - 1) * c + i - 1] == '.')
                cnt++;
            ans += (long long)cnt * cnt;
        }
    }
    printf("%lld", ans);
}