#include <bits/stdc++.h>
using namespace std;

vector<node> a[1001];
int dp[1001][1001];

int main()
{
    int l, n, b;
    cin.tie(0);
    cin >> l >> n >> b;
    for (int i = 1; i <= n; i++)
    {
        int x, w, f, c;
        cin >> x >> w >> f >> c;
        a[i] = make_tuple(x, w, f, c);
    }
    sort(a + 1, a + n + 1);
    for (int i = 1; i <= l; i++)
    for (int j = 0; j <= b; j++)
    dp[i][j] = INT_MIN;
    for (int i = 0, j = 1; i < l; i++)
    {
        while (j <= n && get<0>(a[j]) == i)
        {
            int x, w, f, c;
            tie(x, w, f, c) = a[j++];
            for (int k = 0; k <= b - c; k++)
                dp[x + w][k + c] = max(dp[x + w][k + c], dp[x][k] + f);
        }
    }
    printf("%d", dp[l][b] > 0 ? dp[l][b] : -1);
    return 0;
}