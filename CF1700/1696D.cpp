#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int treeup[1000001], treedown[1000001], a[250001];

void update(int tree[], int node, int l, int r, int x, int val)
{
    if (l == r)
    {
        tree[node] = val;
        return;
    }
    int mid = (l + r) >> 1;
    if (x <= mid)
        update(tree, node << 1, l, mid, x, val);
    else
        update(tree, node << 1 | 1, mid + 1, r, x, val);
    tree[node] = min(tree[node << 1], tree[node << 1 | 1]);
}

int get(int tree[], int node, int l, int r, int x, int y)
{
    if (x > y)
        return INT_MAX;
    if (l == x && r == y)
        return tree[node];
    int mid = (l + r) >> 1;
    if (y <= mid)
        return get(tree, node << 1, l, mid, x, y);
    if (x > mid)
        return get(tree, node << 1 | 1, mid + 1, r, x, y);
    return min(get(tree, node << 1, l, mid, x, mid), get(tree, node << 1 | 1, mid + 1, r, mid + 1, y));
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int T;
    cin >> T;
    while (T--)
    {
        int n, ans;
        cin >> n;
        stack<pair<int, int>> up, down;
        for (int i = 1; i <= n; i++)
        {
            int x;
            cin >> x;
            while (!up.empty() && up.top().first >= x)
            {
                update(treeup, 1, 1, n, up.top().second, INT_MAX);
                up.pop();
            }
            while (!down.empty() && down.top().first <= x)
            {
                update(treedown, 1, 1, n, down.top().second, INT_MAX);
                down.pop();
            }
            if (i == 1)
                ans = 0;
            else
                ans = min(get(treeup, 1, 1, n, down.empty() ? 1 : down.top().second + 1, i - 1), get(treedown, 1, 1, n, up.empty() ? 1 : up.top().second + 1, i - 1)) + 1;
            update(treeup, 1, 1, n, i, ans);
            update(treedown, 1, 1, n, i, ans);
            up.emplace(x, i);
            down.emplace(x, i);
        }
        cout << ans << '\n';
    }
    return 0;
}
