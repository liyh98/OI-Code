#include <bits/stdc++.h>
using namespace std;

bool v[6001];
int r[6001];
vector<int> e[6001];

pair<int, int> dfs(int x)
{
    int ret0 = 0, ret1 = 0;
    for (int nex : e[x])
    {
        auto p = dfs(nex);
        ret0 += max(p.first, p.second);
        ret1 += p.first;
    }
    return make_pair(ret0, ret1 + r[x]);
}

int main()
{
    int n;
    scanf("%d", &n);
    for (int i = 1; i <= n; i++)
        scanf("%d", &r[i]);
    for (int i = 1; i < n; i++)
    {
        int k, l;
        scanf("%d%d", &l, &k);
        e[k].push_back(l);
        v[l] = 1;
    }
    int rt = 0;
    for (int i = 1; i <= n; i++)
        if (!v[i])
            rt = i;
    auto p = dfs(rt);
    printf("%d", max(p.first, p.second));
    return 0;
}