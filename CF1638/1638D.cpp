#include <bits/stdc++.h>
using namespace std;

int a[1001][1001];
bool v[1001][1001];
vector<array<int, 3>> coloring;
int n, m;

inline void color(int x, int y, int c)
{
    coloring.push_back({x, y, c});
    a[x][y] = a[x][y + 1] = a[x + 1][y] = a[x + 1][y + 1] = 0;
}
inline int check(int x, int y)
{
    if (x <= 0 || y <= 0 || x >= n || y >= m)
        return 0;
    int c = 0;
    for (int i = x; i <= x + 1; i++)
        for (int j = y; j <= y + 1; j++)
            if (a[i][j])
            {
                if (!c)
                    c = a[i][j];
                else if (a[i][j] != c)
                    return 0;
            }
    return c;
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
            cin >> a[i][j];
    queue<pair<int, int>> q;
    for (int i = 1; i < n; i++)
        for (int j = 1; j < m; j++)
        {
            if (check(i, j))
            {
                q.emplace(i, j);
                v[i][j] = 1;
                color(i, j, check(i, j));
            }
        }
    while (!q.empty())
    {
        auto [x, y] = q.front();
        q.pop();
        for (int i = x - 1; i <= x + 1; i++)
            for (int j = y - 1; j <= y + 1; j++)
            {
                if (check(i, j) && !v[i][j])
                {
                    q.emplace(i, j);
                    v[i][j] = 1;
                    color(i, j, check(i, j));
                }
            }
    }
    bool ans = 1;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
            if (a[i][j])
                ans = 0;
    if (ans)
    {
        cout << coloring.size() << '\n';
        reverse(coloring.begin(), coloring.end());
        for (auto &[x, y, c] : coloring)
            cout << x << ' ' << y << ' ' << c << '\n';
    }
    else
        cout << -1;
    return 0;
}
