#include <bits/stdc++.h>
using namespace std;

int a[51][51], sub[51];
bool taken[51];

inline void Odd(int n)
{
    taken[sub[1]] = taken[sub[2]] = taken[sub[n]] = 1;
    int now = 1;
    for (int i = 3; i < n; i++)
    {
        while (taken[now])
            now++;
        taken[sub[i] = now] = 1;
    }
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)
            a[i][j] = (j - i + n) % n + 1;
    for (int i = 1; i <= n; i++)
        swap(a[n - 1][i], a[n][i]);
}

inline void Even(int n)
{
    taken[sub[1]] = taken[sub[2]] = 1;
    int now = 1;
    for (int i = 3; i <= n; i++)
    {
        while (taken[now])
            now++;
        taken[sub[i] = now] = 1;
    }
    for (int i = 1; i <= n - 2; i++)
        a[i][i] = 1;
    a[n - 1][n - 1] = a[n][n] = 2;
    a[n - 1][n] = a[n][n - 1] = 1;
    for (int i = 1; i <= n - 3; i++)
        a[i][i + 1] = 2;
    a[n - 2][1] = 2;
    for (int i = 1; i <= n - 2; i++)
    {
        int now = 2 + i;
        for (int j = 3; j <= n; j++)
        {
            while (a[i][now])
                now = now == n ? 1 : now + 1;
            a[i][now] = j;
        }
    }
    for (int i = 1; i <= n - 2; i++)
    {
        memset(taken, 0, sizeof taken);
        for (int j = 1; j <= n - 2; j++)
            taken[a[j][i]] = 1;
        for (int j = 1; j < i; j++)
            taken[a[n - 1][j]] = 1;
        for (int j = 1; j <= n; j++)
            if (!taken[j])
            {
                a[n - 1][i] = j;
                break;
            }
        memset(taken, 0, sizeof taken);
        for (int j = 1; j <= n - 1; j++)
            taken[a[j][i]] = 1;
        for (int j = 1; j < i; j++)
            taken[a[n][j]] = 1;
        for (int j = 1; j <= n; j++)
            if (!taken[j])
            {
                a[n][i] = j;
                break;
            }
    }
}
inline void TC()
{
    int n, k;
    scanf("%d%d", &n, &k);
    if (k == n + 1 || k == n * n - 1 || (n == 3 && k % n))
    {
        puts("IMPOSSIBLE");
        return;
    }
    puts("POSSIBLE");
    memset(taken, 0, sizeof taken);
    memset(sub, 0, sizeof sub);
    memset(a, 0, sizeof a);
    if (k % n == 0)
    {
        int d = k / n - 1;
        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= n; j++)
                printf("%d ", (j - i + d + n) % n + 1);
            putchar('\n');
        }
    }
    else
    {
        int d = k / n, r = k % n;
        if (r != 1 && d + ((r + 1) >> 1) <= n)
        {
            if (r & 1)
            {
                sub[1] = d;
                sub[2] = d + (r >> 1);
                sub[n] = d + ((r + 1) >> 1);
                Odd(n);
                //puts("111");
            }
            else
            {
                sub[1] = d;
                sub[2] = d + (r >> 1);
                Even(n);
                //puts("118");
            }
        }
        else if (d - 1 + ((r + n + 1) >> 1) <= n)
        {
            if ((r + n) & 1)
            {
                sub[1] = d - 1;
                sub[2] = d - 1 + ((r + n) >> 1);
                sub[n] = d - 1 + ((r + n + 1) >> 1);
                Odd(n);
                //puts("129");
            }
            else
            {
                sub[1] = d - 1;
                sub[2] = d - 1 + ((r + n) >> 1);
                Even(n);
                //puts("136");
            }
        }
        else if (r != n - 1)
        {
            if (((d + 1) * n - k) & 1)
            {
                sub[1] = d + 1;
                sub[2] = (k - (d + 1) * (n - 2)) >> 1;
                sub[n] = sub[2] + 1;
                Odd(n);
                //puts("147");
            }
            else
            {
                sub[1] = d + 1;
                sub[2] = (k - (d + 1) * (n - 2)) >> 1;
                Even(n);
                //puts("154");
            }
        }
        else
        {
            if (((d + 2) * n - k) & 1)
            {
                sub[1] = d + 2;
                sub[2] = (k - (d + 2) * (n - 2)) >> 1;
                sub[n] = sub[2] + 1;
                Odd(n);
                //puts("165");
            }
            else
            {
                sub[1] = d + 2;
                sub[2] = (k - (d + 2) * (n - 2)) >> 1;
                Even(n);
                //puts("172");
            }
        }
        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= n; j++)
                printf("%d ", sub[a[i][j]]);
            putchar('\n');
        }
    }
}

int main()
{
    int T;
    scanf("%d", &T);
    for (int i = 1; i <= T; i++)
    {
        printf("Case #%d: ", i);
        TC();
    }
    return 0;
}