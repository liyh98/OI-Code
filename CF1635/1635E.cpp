#include <bits/stdc++.h>
using namespace std;

vector<tuple<int, int, int>> e[200001];
bool v[200001], ve[200001], dir[200001], flag;
int pos[200001];
int ind[200001];
vector<int> cc;
vector<int> topoE[200001];

void dfs(int x, int dir)
{
    cc.push_back(x);
    ::dir[x] = dir;
    v[x] = 1;
    for (auto &[nex, t, id] : e[x])
    {
        if (ve[id])
        {
            continue;
        }
        ve[id] = 1;
        if (dir ^ t)
            topoE[nex].push_back(x), ind[x]++;
        else
            topoE[x].push_back(nex), ind[nex]++;
        if (!v[nex])
            dfs(nex, !dir);
        else if (::dir[nex] == dir)
        {
            flag = 1;
        }
    }
}

/* void reset(int x)
{
    topoE[x].clear();
    v[x] = 0;
    ind[x] = 0;
    for (auto &[nex, t, id] : e[x])
    {
        ve[id] = 0;
        if (v[nex])
            reset(nex);
    }
} */

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int n, m;
    cin >> n >> m;
    for (int i = 1; i <= m; i++)
    {
        int t, x, y;
        cin >> t >> x >> y;
        e[x].emplace_back(y, t - 1, i);
        e[y].emplace_back(x, t - 1, i);
    }
    bool ans = 1;
    int p = 0;
    for (int i = 1; i <= n; i++)
    {
        if (!v[i])
        {
            cc.clear();
            dfs(i, 0);
            int c = cc.size();
            if (flag)
            {
                ans = 0;
                break;
            }
            queue<int> q;
            for (int &x : cc)
                if (ind[x] == 0)
                    q.push(x);
            for (int i = 1; i <= c; i++)
            {
                if (q.empty())
                {
                    ans = 0;
                    break;
                }
                int x = q.front();
                q.pop();
                pos[x] = ++p;
                for (int &nex : topoE[x])
                    if (--ind[nex] == 0)
                        q.push(nex);
            }
            /*             if (ans)
                            continue;
                        reset(i);
                        cc.clear();
                        dfs(i, 1);
                        for (int &x : cc)
                            if (ind[x] == 0)
                                q.push(x);
                        ans = 1;
                        for (int i = 1; i <= c; i++)
                        {
                            if (q.empty())
                            {
                                ans = 0;
                                break;
                            }
                            int x = q.front();
                            q.pop();
                            pos[x] = ++p;
                            for (int &nex : topoE[x])
                                if (--ind[nex] == 0)
                                    q.push(nex);
                        }
             */
            if (!ans)
                break;
        }
    }
    if (!ans)
    {
        cout << "NO\n";
    }
    else
    {
        cout << "YES\n";
        for (int i = 1; i <= n; i++)
            cout << (dir[i] ? 'R' : 'L') << ' ' << pos[i] << '\n';
    }
    return 0;
}
