#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int n, K;
    cin >> n >> K;
    if (K == 1)
    {
        cout << 1;
        return 0;
    }
    K = min(K, n);
    vector<vector<int>> f(n + 1, vector<int>(n + 1));
    for (int i = 1; i <= n; i++)
    {
        f[i][i] = 1;
        for (int j = 1; j * j <= i; j++)
        {
            if (i % j == 0)
            {
                for (int k = 1; k + i <= n - (j > 1); k++)
                    f[i + k][gcd(j, k)] += f[i][j] * (K - 1);
                int x = i / j;
                if (x == j)
                    continue;
                for (int k = 1; k + i <= n - 1; k++)
                    f[i + k][gcd(x, k)] += f[i][j] * (K - 1);
            }
        }
    }
    cout << f[n][1];
    return 0;
}
