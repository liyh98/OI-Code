#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int n, Q;
    cin >> n >> Q;
    vector<vector<int>> edges(n + 1, vector<int>());
    while (Q--)
    {
        int l, r;
        cin >> l >> r;
        edges[l - 1].push_back(r);
        edges[r].push_back(l - 1);
    }
    vector<bool> v(n + 1);
    v[0] = 1;
    queue<int> q;
    q.push(0);
    while (!q.empty())
    {
        int x = q.front();
        q.pop();
        for (int &nex : edges[x])
        {
            if (v[nex])
                continue;
            v[nex] = 1;
            q.push(nex);
        }
    }
    puts(v[n] ? "Yes" : "No");
    return 0;
}
