#include <bits/stdc++.h>
using namespace std;

int c[100001][3], st[100001], trans[] = {3, 5, 1, 4, 0, 2};
vector<int> e[100001];

vector<long long> dfs(int x, int pre) //0 12 1 13 2 21 3 23 4 31 5 32
{
    vector<long long> ans;
    ans.resize(6);
    for (int i = 0; i < 6; i++)
        ans[i] = c[x][i / 2];
    for (int i : e[x])
    {
        if (i != pre)
        {
            vector<long long> ret = dfs(i, x);
            for (int j = 0; j < 6; j++)
                ans[j] += ret[trans[j]];
        }
    }
    return ans;
}

void rdfs(int x, int pre, int state)
{
    st[x] = state / 2 + 1;
    for (int i : e[x])
    {
        if (i != pre)
            rdfs(i, x, trans[state]);
    }
}
int main()
{
    int n;
    scanf("%d", &n);
    for (int i = 0; i < 3; i++)
    {
        for (int j = 1; j <= n; j++)
            scanf("%d", &c[j][i]);
    }
    for (int i = 1; i < n; i++)
    {
        int u, v;
        scanf("%d%d", &u, &v);
        e[u].push_back(v);
        e[v].push_back(u);
    }
    int rt = 0;
    for (int i = 1; i <= n; i++)
    {
        if (e[i].size() == 1) rt = i;
        if (e[i].size() > 2)
        {
            puts("-1");
            return 0;
        }
    }
    vector<long long> ret = dfs(rt, 0);
    int state = 0;
    for (int i = 1; i < 6; i++)
        if (ret[state] > ret[i])
            state = i;
    printf("%lld\n", ret[state]);
    rdfs(rt, 0, state);
    for (int i = 1; i <= n; i++)
        printf("%d ", st[i]);
    return 0;
}