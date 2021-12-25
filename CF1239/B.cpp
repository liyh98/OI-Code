#include <bits/stdc++.h>
using namespace std;

char s[600005];
int a[600001];
int main()
{
    int n, mi, cnt = 1;
    scanf("%d%s", &n, s + 1);
    mi = n;
    for (int i = 1; i <= n; i++)
    {
        if (s[i] == '(')
            a[i] = a[i - 1] + 1;
        else
            a[i] = a[i - 1] - 1;
        if (mi > a[i])
            mi = a[i], cnt = 1;
        else if (mi == a[i])
            cnt++;
    }
    for (int i = 1; i <= n; i++)
        a[i + n] = a[i], s[i + n] = s[i];
    if (a[n])
    {
        printf("0\n1 1");
        return 0;
    }
    int ans = cnt, l = 1, r = 1;
    for (int i = 1; i <= n + n; i++)
    {
        if (s[i] == '(')
        {
            int j = i, c2 = 0;
            while (j <= n + n && a[j] >= mi + 2)
            {
                c2 += a[j] == mi + 2;
                if (j - i >= n)
                {
                    do
                    {
                        c2 -= a[i] == mi + 2;
                        i++;
                    } while (s[i] == ')');
                }
                if (s[j + 1] == ')' && cnt + c2 > ans)
                {
                    ans = cnt + c2;
                    l = i, r = j + 1;
                }
                j++;
            }
            i = j;
        }
    }
    for (int i = 1; i <= n + n; i++)
    {
        if (s[i] == '(')
        {
            int j = i, c1 = 0;
            while (j <= n + n && a[j] >= mi + 1)
            {
                c1 += a[j] == mi + 1;
                if (j - i >= n)
                {
                    do
                    {
                        c1 -= a[i] == mi + 1;
                        i++;
                    } while (s[i] == ')');
                }
                if (s[j + 1] == ')' && c1 > ans)
                {
                    ans = c1;
                    l = i, r = j + 1;
                }
                j++;
            }
            i = j;
        }
    }
    if (r > n) r -= n;
    printf("%d\n%d %d", ans, l, r);
    return 0;
}