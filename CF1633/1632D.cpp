#include <bits/stdc++.h>
using namespace std;

int g[200001][18];

int gcd(int x, int y) { return x ? gcd(y % x, x) : y; }

int get(int l, int r)
{
    int ret = 0;
    for (int i = 0, b = 1; i < 18; i++, b <<= 1)
    {
        if ((r - l + 1) & b)
            ret = gcd(ret, g[l][i]), l += b;
    }
    return ret;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++)
        cin >> g[i][0];
    for (int i = 0, b = 1; i < 17; i++, b <<= 1)
        for (int j = n - b; j > 0; j--)
            g[j][i + 1] = gcd(g[j][i], g[j + b][i]);
    int ans = 0;
    for (int i = 1, j = 1; i <= n; i++)
    {
        while (j <= i && get(j, i) < i - j + 1)
            j++;
        if (get(j, i) == i - j + 1)
            ans++, j = i + 1;
        cout << ans << ' ';
    }
    return 0;
}
