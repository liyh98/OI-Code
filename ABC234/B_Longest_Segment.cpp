#include <bits/stdc++.h>
using namespace std;

int x[101], y[101];

int dis(int a, int b)
{
    return (x[a] - x[b]) * (x[a] - x[b]) + (y[a] - y[b]) * (y[a] - y[b]);
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++)
        cin >> x[i] >> y[i];
    int ans = 0;
    for (int i = 1; i < n; i++)
        for (int j = i + 1; j <= n; j++)
            ans = max(ans, dis(i, j));
    printf("%.10lf", sqrt(ans));
    return 0;
}
