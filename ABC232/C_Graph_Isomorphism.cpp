#include <bits/stdc++.h>
using namespace std;

bool a[9][9], b[9][9];

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int n, m;
    cin >> n >> m;
    for (int i = 1; i <= m; i++)
    {
        int x, y;
        cin >> x >> y;
        a[x][y] = a[y][x] = 1;
    }
    for (int i = 1; i <= m; i++)
    {
        int x, y;
        cin >> x >> y;
        b[x][y] = b[y][x] = 1;
    }
    vector<int> ref(n + 1);
    for (int i = 1; i <= n; i++)
        ref[i] = i;
    bool flag = 0;
    do
    {
        bool all = 1;
        for (int i = 1; i <= n; i++)
            for (int j = 1; j <= n; j++)
                if (a[i][j] != b[ref[i]][ref[j]])
                {
                    all = 0;
                    break;
                }
        if (all)
        {
            flag = 1;
            break;
        }
    } while (next_permutation(ref.begin(), ref.end()));
    puts(flag ? "Yes" : "No");
    return 0;
}
