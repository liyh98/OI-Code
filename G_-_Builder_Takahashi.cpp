#include <atcoder/maxflow>
#include <bits/stdc++.h>
using namespace std;
using namespace atcoder;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int n, m;
    cin >> n >> m;
    mf_graph<long long> graph(n << 1);
    while (m--)
    {
        int x, y;
        cin >> x >> y;
        graph.add_edge(x - 1 + n, y - 1, 1e12);
        graph.add_edge(y - 1 + n, x - 1, 1e12);
    }
    for (int i = 1; i <= n; i++)
    {
        int c;
        cin >> c;
        graph.add_edge(i - 1, i - 1 + n, c);
    }
    cout << graph.flow(n, n - 1) << '\n';
    auto cut = graph.min_cut(n);
    vector<int> ans;
    for (int i = 1; i <= n; i++)
    {
        if (cut[i - 1] && !cut[i - 1 + n])
            ans.push_back(i);
    }
    cout << ans.size() << '\n';
    for (int &x : ans)
        cout << x << ' ';
    return 0;
}
