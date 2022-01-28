#include <bits/stdc++.h>
using namespace std;

int a[200001], b[200001], r[200001], tree[200001], n;

int get(int x)
{
    int ret = 0;
    for (; x; x -= x & -x)
        ret = max(ret, tree[x]);
    return ret;
}

void update(int x, int val)
{
    for (; x <= n; x += x & -x)
        tree[x] = max(tree[x], val);
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n;
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    for (int i = 1; i <= n; i++)
    {
        cin >> b[i];
        r[b[i]] = i;
    }
    int ans = 0;
    for (int i = 1; i <= n; i++)
    {
        vector<pair<int, int>> temp;
        for (int j = a[i]; j <= n; j += a[i])
        {
            int ret = get(r[j] - 1) + 1;
            ans = max(ans, ret);
            temp.emplace_back(r[j], ret);
        }
        for (auto &[x, val] : temp)
            update(x, val);
    }
    cout << ans;
    return 0;
}
