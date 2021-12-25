#include <bits/stdc++.h>
using namespace std;

bool link[205][205], used[205], stx[205], sty[205], a[105][105];
char s[105];
int bel[205];

inline void work()
{
    memset(link, 0, sizeof link);
    memset(a, 0, sizeof a);
    int n;
    scanf("%d", &n);
    for (int i = 1; i <= n; i++)
    {
        scanf("%s", s + 1);
        for (int j = 1; j <= n; j++)
        {
            if (s[j] == '.')
                a[i][j] = 1, link[j - i + n][i + j - 1] = 1;
        }
    }
    int ans = 10000;
    for (int i = 0; i < 2; i++)
        for (int j = 0; j < 2; j++)
        {
            stx[n] = i;
            stx[n + 1] = j;
            for (int k = 1; k < 2 * n; k++)
            {
                int t = k & 1 ? n : n + 1;
                sty[k] = stx[t] ^ link[t][k];
            }
            for (int x = 1; x <= n; x++)
                for (int y = 1; y <= n; y++)
                    stx[y - x + n] = a[x][y] ^ sty[x + y - 1];
            bool flag = 1;
            for (int x = 1; x <= n; x++)
            {
                for (int y = 1; y <= n; y++)
                    if (stx[y - x + n] ^ a[x][y] ^ sty[x + y - 1])
                    {
                        flag = 0;
                        break;
                    }
                if (!flag)
                    break;
            }
            if (flag)
            {
                int tot = 0;
                for (int k = 1; k < 2 * n; k++)
                    tot += stx[k], tot += sty[k];
                ans = min(ans, tot);
            }
        }
    printf("%d\n", ans);
}
int main()
{
    int T;
    scanf("%d", &T);
    for (int i = 1; i <= T; i++)
    {
        printf("Case #%d: ", i);
        work();
    }
    return 0;
}