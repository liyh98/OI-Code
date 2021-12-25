#include <bits/stdc++.h>
using namespace std;

char s[101], re[] = " 0123456789poiuytrewqlkjhgfdsamnbvcxzPOIUYTREWQLKJHGFDSAMNBVCXZ";
bool a[101][101];
int ans[101][101];
inline void work()
{
    int r, c, k, tot = 0, now = 0, chic = 1;
    scanf("%d%d%d", &r, &c, &k);
    for (int i = 1; i <= r; i++)
    {
        scanf("%s", s + 1);
        for (int j = 1; j <= c; j++)
            tot += (a[i][j] = s[j] == 'R');
    }
    for (int i = 1; i <= r; i++)
    {
        bool p = i & 1;
        for (int j = p ? 1 : c; p ? j <= c : j; p ? j++ : j--)
        {
            if (a[i][j])
            {
                if (now == (tot / k) + (chic <= tot % k))
                    now = 0, chic++;
                now++;
            }
            ans[i][j] = chic;
        }
    }
    for (int i = 1; i <= r; i++)
    {
        for (int j = 1; j <= c; j++)
            putchar(re[ans[i][j]]);
        putchar('\n');
    }
}
int main()
{
    int T;
    scanf("%d", &T);
    while (T--)
        work();
    return 0;
}