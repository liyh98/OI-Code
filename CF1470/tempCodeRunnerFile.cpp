#include <bits/stdc++.h>
using namespace std;

vector<int> e[300001];
bool v[300001], inq[300001];
int d[300001];
void TC()
{
    int n, m;
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; i++)
    {
        e[i].clear();
        inq[i] = v[i] = 0;
        d[i] = 0;
    }
    while (m--)
    {
        int u, v;
        scanf("%d%d", &u, &v);
        e[u].push_back(v);
        e[v].push_back(u);
    }
    queue<int> aval;
    vector<int> ans;
    int cnt = 0;
    aval.push(1);
    while (!aval.empty())
    {
        int x = aval.front();
        aval.pop();
        if (v[x])
            continue;
        ans.push_back(x);
        v[x] = 1;
        cnt++;
        for (int nex : e[x])
        {
            if (!v[nex])
            {
                v[nex] = 1;
                cnt++;
                for (int nnex : e[nex])
                {
                    if (!v[nnex] & !inq[nnex])
                        aval.push(nnex), inq[nnex] = 1;
                }
            }
        }
    }
    if (cnt != n)
        puts("NO");
    else
    {
        puts("YES");
        printf("%d\n", ans.size());
        for (int x : ans)
            printf("%d ", x);
        putchar('\n');
    }
}
int main()
{
    int T;
    scanf("%d", &T);
    while (T--)
        TC();
    return 0;
}