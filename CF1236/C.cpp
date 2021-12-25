#include <bits/stdc++.h>
using namespace std;

int a[301][301];
vector<int> ans[301];
int main()
{
    int n;
    scanf("%d", &n);
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
            ans[i & 1 ? j : n + 1 - j].push_back((i - 1) * n + j);
    }
    for (int i = 1; i <= n; i++)
    {
        for (int j = 0; j < n - 1; j++)
            printf("%d ", ans[i][j]);
        printf("%d\n", ans[i][n - 1]);
    }
    return 0;
}