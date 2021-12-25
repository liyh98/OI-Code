#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> pii;
priority_queue<pii, vector<pii>, greater<pii>> pq;
vector<pii> e[5001];
bool v[5001];

int main()
{
    int n, m;
    scanf("%d%d", &n, &m);
    while (m--)
    {
        int x, y, z;
        scanf("%d%d%d", &x, &y, &z);
        e[x].emplace_back(y, z);
        e[y].emplace_back(x, z);
    }
    pq.emplace(0, 1);
    int cnt = 0;
    long long ans = 0;
    while (!pq.empty())
    {
        int w, u;
        tie(w, u) = pq.top();
        pq.pop();
        if (v[u])
            continue;
        v[u] = 1;
        ans += w;
        cnt++;
        for (pii p : e[u])
        {
            if (v[p.first])
                continue;
            pq.emplace(p.second, p.first);
        }
    }
    if (cnt < n)
        puts("orz");
    else
        printf("%lld", ans);
    return 0;
}