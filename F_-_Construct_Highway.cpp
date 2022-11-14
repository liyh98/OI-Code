#include <bits/stdc++.h>
using namespace std;

int d[200001];
vector<int> e[200001];
bool v[200001], flag;
queue<int> soc;

void dfs(int x, int pre)
{
    v[x] = 1;
    if (d[x])
        soc.push(x);
    for (int &nex : e[x])
    {
        if (nex != pre)
        {
            if (v[nex])
            {
                flag = 1;
                return;
            }
            dfs(nex, x);
            if (flag)
                return;
        }
    }
}

int count(int x, int pre, vector<int> &ls)
{
    int ret = 0;
    ret += d[x];
    if (d[x])
        ls.push_back(x);
    v[x] = 1;
    for (int &nex : e[x])
    {
        if (nex != pre)
        {
            if (v[nex])
            {
                flag = 1;
                return 0;
            }
            ret += count(nex, x, ls);
            if (flag)
                return 0;
        }
    }
    return ret;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int n, m;
    cin >> n >> m;
    long long tot = 0;
    for (int i = 1; i <= n; i++)
        cin >> d[i], tot += d[i];
    while (m--)
    {
        int a, b;
        cin >> a >> b;
        d[a]--;
        d[b]--;
        if (d[a] < 0 || d[b] < 0)
        {
            puts("-1");
            return 0;
        }
        e[a].push_back(b);
        e[b].push_back(a);
    }
    vector<pair<int, int>> ans;
    dfs(1, 0);
    if (flag)
    {
        puts("-1");
        return 0;
    }
    vector<pair<int, int>> cc;
    vector<vector<int>> l(n + 1);
    for (int i = 1; i <= n; i++)
    {
        if (!v[i] && d[i])
        {
            vector<int> t;
            int res = count(i, 0, t);
            if (flag)
            {
                puts("-1");
                return 0;
            }
            cc.emplace_back(res, i);
            l[i] = t;
        }
    }
    for (int i = 1; i <= n; i++)
        if (!v[i])
        {
            puts("-1");
            return 0;
        }
    sort(cc.begin(), cc.end(), greater());
    for (auto &[_, x] : cc)
    {
        if (soc.empty())
        {
            puts("-1");
            return 0;
        }
        int fa = soc.front();
        ans.emplace_back(fa, x);
        d[x]--;
        if (--d[fa] == 0)
            soc.pop();
        for (int &x : l[x])
            if (d[x])
                soc.push(x);
    }
    if (!soc.empty())
    {
        puts("-1");
        return 0;
    }
    for (auto &[f, s] : ans)
        cout << f << ' ' << s << '\n';
    return 0;
}
