#include <bits/stdc++.h>
using namespace std;

string c;
int l[200001], r[200001], k;
vector<int> order;
bool f[200001], used[200001];

void dfs(int x)
{
    if (l[x])
        dfs(l[x]);
    order.push_back(x);
    if (r[x])
        dfs(r[x]);
}

bool work(int x, int d = 1)
{

    if (d > k)
        return 0;
    if (l[x])
    {
        if (work(l[x], d + 1))
            used[x] = 1;
    }
    if (!used[x])
    {
        if (f[x])
        {
            used[x] = 1;
            k -= d;
        }
        else
            return 0;
    }
    if (r[x])
    {
        if (used[x])
            work(r[x]);
        if (!used[x] && work(r[x], d + 1))
            used[x] = 1;
    }
    return used[x];
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin >> n >> k;
    cin >> c;
    for (int i = 1; i <= n; i++)
        cin >> l[i] >> r[i];
    dfs(1);
    for (int i = n - 2; i >= 0; i--)
    {
        if (c[order[i] - 1] < c[order[i + 1] - 1])
            f[order[i]] = 1;
        else if (c[order[i] - 1] == c[order[i + 1] - 1])
            f[order[i]] = f[order[i + 1]];
    }
    work(1);
    for (int &x : order)
    {
        cout << c[x - 1];
        if (used[x])
            cout << c[x - 1];
    }
    return 0;
}
