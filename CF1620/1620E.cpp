#include <bits/stdc++.h>
using namespace std;

int head[500001], cnt, c[500001];

vector<int> edges[500001];
vector<int> a;

void dfs(int x, int color)
{
    c[x] = color;
    for (int &nex : edges[x])
        dfs(nex, color);
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int q;
    cin >> q;
    while (q--)
    {
        int op, x, y;
        cin >> op >> x;
        if (op == 1)
        {
            if (!head[x])
                head[x] = ++cnt;
            a.push_back(head[x]);
            // cout << x << ' ' << head[x] << '\n';
        }
        else
        {
            cin >> y;
            if (x == y)
                continue;
            if (!head[y])
                head[y] = head[x];
            else if (head[x])
                edges[head[y]].push_back(head[x]);
            head[x] = 0;
        }
    }
    for (int i = 1; i <= 500000; i++)
    {
        if (head[i])
            dfs(head[i], i);
    }
    for (int &x : a)
        cout << c[x] << ' ';
    return 0;
}
