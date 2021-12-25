#include <bits/stdc++.h>
using namespace std;

vector<int> e[100001];
int ans, dfn[100001], low[100001], cnt, scc, bel[100001];
bool ins[100001], v[100001];
stack<int> s;
void tarjan(int x)
{
    dfn[x] = low[x] = ++cnt;
    v[x] = ins[x] = 1;
    s.push(x);
    for (int y : e[x])
    {
        if (!v[y])
        {
            tarjan(y);
            low[x] = min(low[x], low[y]);
        }
        else if (ins[y])
            low[x] = min(low[x], dfn[y]);
    }
    if (low[x] == dfn[x])
    {
        int sz = 0, y;
        scc++;
        do
        {
            ins[y = s.top()] = 0;
            sz++;
            bel[y] = scc;
            s.pop();
        } while (y != x);
        if (sz > 1)
            ans++;
    }
}
int main()
{
    int n, m;
    scanf("%d%d", &n, &m);
    while (m--)
    {
        int a, b;
        scanf("%d%d", &a, &b);
        e[a].push_back(b);
    }
    for (int i = 1; i <= n; i++)
        if (!v[i])
            tarjan(i);
    printf("%d", ans);
    return 0;
}