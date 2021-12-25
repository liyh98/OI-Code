#include <bits/stdc++.h>
using namespace std;

int B, cnt = 0, tc;
char name[101], str[101];
bool ans[101];
ofstream query;

inline void flip()
{
    for (int i = 1; i + i < B; i++)
        swap(ans[i], ans[B + 1 - i]);
}

inline void comp()
{
    for (int i = 1; i <= B; i++)
        ans[i] ^= 1;
}

inline bool test(int x)
{
    int ret;
    printf("%d\n", x);
    sprintf(name, "Q%d.txt", ++cnt);
    query.open(name);
    query << tc << ' ' << x << '\n';
    fflush(stdout);
    scanf("%d", &ret);
    query << ret;
    query.close();
    return (bool)ret;
}
inline void TC()
{
    int c = 0, now = 1, s = 0, d = 0;
    cnt = 0;
    for (int i = 1; i < 15; i++)
    {
        c = 0;
        bool fliped = 0, comped = 0;
        if (s)
        {
            c++;
            comped = test(s) ^ ans[s];
        }
        if (d)
        {
            c++;
            fliped = test(d) ^ ans[d] ^ comped;
        }
        if (fliped)
            flip();
        if (comped)
            comp();
        if (c == 1)
            c++, test(1);
        while (c < 10 && now + now < B + 2)
        {
            ans[now] = test(now);
            ans[B + 1 - now] = test(B + 1 - now);
            if (ans[now] == ans[B + 1 - now] && !s)
                s = now;
            if (ans[now] != ans[B + 1 - now] && !d)
                d = now;
            c += 2, now++;
        }
        if (now + now > B + 1)
            break;
    }
    for (int i = 1; i <= B; i++)
        putchar('0' + ans[i]);
    putchar('\n');
    fflush(stdout);
    scanf("%s", str);
}

int main()
{
    int T;
    scanf("%d%d", &T, &B);
    for (tc = 1; tc <= T; tc++)
        TC();
    return 0;
}