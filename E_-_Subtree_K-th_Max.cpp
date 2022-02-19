#include <bits/stdc++.h>
using namespace std;

int x[100001], ans[100001];
vector<int> e[100001];
vector<pair<int, int>> queries[100001];
#define N 20

inline void merge(vector<int> &now, const vector<int> &next)
{
    vector<int> t;
    t.reserve(N);
    for (int i = 0, p1 = 0, p2 = 0; i < N; i++)
    {
        if (p2 >= N || (p1 < N && now[p1] >= next[p2]))
            t.push_back(now[p1++]);
        else
            t.push_back(next[p2++]);
    }
    now = t;
}
vector<int> dfs(int x, int pre)
{
    vector<int> now(N);
    now[0] = ::x[x];
    for (int &nex : e[x])
    {
        if (nex == pre)
            continue;
        merge(now, dfs(nex, x));
    }
    for (auto &[k, id] : queries[x])
        ans[id] = now[k - 1];
    return now;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int n, q;
    cin >> n >> q;
    for (int i = 1; i <= n; i++)
        cin >> x[i];
    for (int i = 1; i < n; i++)
    {
        int a, b;
        cin >> a >> b;
        e[a].push_back(b);
        e[b].push_back(a);
    }
    for (int i = 1; i <= q; i++)
    {
        int v, k;
        cin >> v >> k;
        queries[v].emplace_back(k, i);
    }
    dfs(1, 0);
    for (int i = 1; i <= q; i++)
        cout << ans[i] << '\n';
    return 0;
}
