#include <bits/stdc++.h>
using namespace std;

int a[10];
bool f[10][170][11];

inline bool work()
{
    int cnt10 = 0;
    for (int i = 1; i <= 9; i++)
    {
        scanf("%d", &a[i]);
        if (a[i] > 9)
            cnt10++;
    }
    if (cnt10 > 1)
        return 1;
    memset(f, 0, sizeof f);
    f[0][80][0] = 1;
    for (int i = 1; i <= 9; i++)
    {
        if (a[i] > 80)
            a[i] = a[i] & 1 ? 79 : 80;
        for (int j = 0; j <= a[i]; j++)
        {
            int p = j * 2 - a[i], d = ((p % 11 * i % 11) + 11) % 11;
            for (int k = -80 + max(0, -p); k <= 80 + min(0, -p); k++)
                for (int l = 0; l < 11; l++)
                    f[i][k + p + 80][(l + d) % 11] |= f[i - 1][k + 80][l];
        }
    }
    return f[9][80][0] | f[9][81][0];
}
int main()
{
    int T;
    scanf("%d", &T);
    for (int i = 1; i <= T; i++)
    {
        printf("Case #%d: ", i);
        puts(work() ? "YES" : "NO");
    }
    return 0;
}