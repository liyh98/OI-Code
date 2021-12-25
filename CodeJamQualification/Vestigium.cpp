#include <bits/stdc++.h>
using namespace std;

int m[101][101];
bool vis[101];

inline void TC()
{
    int n, k = 0, r = 0, c = 0;
    scanf("%d", &n);
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)
            scanf("%d", &m[i][j]);
    for (int i = 1; i <= n; i++) k += m[i][i];
    for (int i = 1; i <= n; i++) {
        memset(vis, 0, sizeof vis);
        for (int j = 1; j <= n; j++) {
            if (!vis[m[i][j]]) vis[m[i][j]] = 1;
            else 
            {
                r++;
                break;
            }
        }
    }
    for (int i = 1; i <= n; i++) {
        memset(vis, 0, sizeof vis);
        for (int j = 1; j <= n; j++) {
            if (!vis[m[j][i]]) vis[m[j][i]] = 1;
            else
            {
                c++;
                break;
            }
        }
    }
    printf("%d %d %d\n", k, r, c);
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