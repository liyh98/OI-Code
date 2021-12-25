#include <bits/stdc++.h>
using namespace std;

int R, C, a[301][301], b[301][301];
const int dx[] = {0, 0, 1, -1}, dy[] = {1, -1, 0, 0};
void dfs(int x, int y)
{
    b[x][y] = max(b[x][y], a[x][y]);
    for (int i = 0; i < 4; i++)
    {
        int tx = x + dx[i], ty = y + dy[i];
        if (tx && tx <= R && ty && ty <= C && b[tx][ty] < b[x][y] - 1)
        {
            b[tx][ty] = b[x][y] - 1;
            dfs(tx, ty);
        }
    }
}

inline void TC()
{
    scanf("%d%d", &R, &C);
    memset(b, 0, sizeof b);
    for (int i = 1; i <= R; i++)
        for (int j = 1; j <= C; j++)
            scanf("%d", &a[i][j]);
    for (int i = 1; i <= R; i++)
        for (int j = 1; j <= C; j++)
            if (a[i][j] > b[i][j])
                dfs(i, j);
    long long ans = 0;
    for (int i = 1; i <= R; i++)
        for (int j = 1; j <= C; j++)
            ans += b[i][j] - a[i][j];
    printf("%lld\n", ans);
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