#include <bits/stdc++.h>
using namespace std;

int n, a[200001], last[200001];
int tree[200001];

void update(int x, int val)
{
    for (; x; x -= x & -x)
        tree[x] = max(tree[x], val);
}

int get(int x)
{
    int ret = INT_MIN;
    for (; x <= n; x += x & -x)
        ret = max(ret, tree[x]);
    return ret;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
        last[a[i]] = i;
        tree[i] = INT_MIN;
    }
    int ans = 0;
    for (int i = 1; i <= n; i++)
    {
        ans = max(ans, i + get(i) - 1);
        update(last[a[i]], ans - i);
    }
    cout << ans;
    return 0;
}
