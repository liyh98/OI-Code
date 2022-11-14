#include <bits/stdc++.h>
using namespace std;

int a[100001][6], w[100001], h[100001];
int T, tree[30000001], ls[30000001], rs[30000001];

void modify(int &x, int pre, int l, int r, int pos)
{
    // cout << x << ' ' << pos << '\n';
    x = ++T;
    ls[x] = ls[pre];
    rs[x] = rs[pre];
    tree[x] = tree[pre];
    if (l == r)
    {
        tree[x]++;
        return;
    }
    int mid = (l + r) >> 1;
    if (pos <= mid)
        modify(ls[x], ls[x], l, mid, pos);
    else
        modify(rs[x], rs[x], mid + 1, r, pos);
    tree[x] = tree[ls[x]] + tree[rs[x]];
}

int find(vector<pair<int, int>> &roots, int n)
{
    // cout << "YES\n";
    // cout.flush();
    // cout << roots.size() << '\n';
    int sum = 0;
    for (auto &[x, sign] : roots)
        sum += tree[x] * sign;
    if (sum == 0)
        return n + 1;
    int l = 1, r = n;
    while (l < r)
    {
        sum = 0;
        for (auto &[x, sign] : roots)
        {
            sum += tree[ls[x]] * sign;
        }
        int mid = (l + r) >> 1;
        if (sum)
        {
            for (auto &[x, sign] : roots)
                x = ls[x];
            r = mid;
        }
        else
        {
            for (auto &[x, sign] : roots)
                x = rs[x];
            l = mid + 1;
        }
    }
    return l;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int n, m;
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
            cin >> a[i][j];
        cin >> w[i];
        h[i] = w[i];
    }
    // puts("L74");
    sort(h + 1, h + n + 1);
    unordered_map<string, int> root;
    int ans = INT_MAX;
    for (int i = 1; i <= n; i++)
    {
        // puts("L80");
        sort(a[i] + 1, a[i] + m + 1);
        bool flag = 1;
        for (int j = 1; j < m; j++)
            if (a[i][j] == a[i][j + 1])
                flag = 0;
        if (!flag)
            continue;
        vector<pair<int, int>> roots;
        for (int b = 0; b < (1 << m); b++)
        {
            string t;
            int c = 0;
            for (int j = 1; j <= m; j++)
                if ((b >> (j - 1)) & 1)
                {
                    t += to_string(a[i][j]) + " ";
                    c++;
                }
            auto it = root.find(t);
            if (it != root.end())
                roots.emplace_back(it->second, c & 1 ? -1 : 1);
        }
        int res = find(roots, n);
        if (res <= n)
            ans = min(ans, h[res] + w[i]);
        int pos = lower_bound(h + 1, h + n + 1, w[i]) - h;
        for (int b = 0; b < (1 << m); b++)
        {
            string t;
            for (int j = 1; j <= m; j++)
                if ((b >> (j - 1)) & 1)
                {
                    t += to_string(a[i][j]) + " ";
                }
            int x = root[t];
            modify(x, x, 1, n, pos);
            // cout << t << ':' << x << '\n';
            root[t] = x;
        }
        // cout << ans << '\n';
    }
    cout << (ans == INT_MAX ? -1 : ans);
    return 0;
}
