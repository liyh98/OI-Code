#include <bits/stdc++.h>
using namespace std;

int a[200001], n;
set<int> pos[200001];
long long tree[2][200001];

void modify(int id, int x, long long val)
{
    if (!x)
        return;
    for (; x <= n; x += x & -x)
        tree[id][x] += val;
}

long long getv(int id, int x)
{
    long long ret = 0;
    for (; x; x -= x & -x)
        ret += tree[id][x];
    return ret;
}

void add(int x, int val)
{
    modify(0, x, val);
    modify(1, x, 1ll * val * (x - 1));
}

long long query(int x)
{
    // cout << getv(0, x) << ' ' << getv(1, x) << '\n';
    return getv(0, x) * x - getv(1, x);
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int q;
    cin >> n >> q;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
        auto it = pos[a[i]].end();
        if (it != pos[a[i]].begin())
        {
            add(i, i - *(--it));
            // cout << "Yay" << i - *it << '\n';
        }
        else
            add(i, i);
        pos[a[i]].insert(i);
    }
    while (q--)
    {
        int op, x, y, k;
        cin >> op;
        if (op == 1)
        {
            cin >> x >> y;
            if (a[x] != y)
            {
                int pre = 0, nex = n + 1;
                auto it = pos[a[x]].find(x);
                if (it != pos[a[x]].begin())
                {
                    pre = *(--it);
                    ++it;
                }
                if (++it != pos[a[x]].end())
                {
                    nex = *it;
                }
                --it;
                if (pre == 0 && nex == n + 1)
                    add(x, -x);
                else if (nex == n + 1)
                    add(x, pre - x);
                else
                    add(x, pre - x), add(nex, x - pre);
                pos[a[x]].erase(it);
                pre = 0, nex = n + 1;
                it = pos[y].insert(x).first;
                if (it != pos[y].begin())
                {
                    pre = *(--it);
                    ++it;
                }
                if (++it != pos[y].end())
                {
                    nex = *it;
                }
                --it;
                if (pre == 0 && nex == n + 1)
                    add(x, x);
                else if (nex == n + 1)
                    add(x, x - pre);
                else
                    add(x, x - pre), add(nex, pre - x);
                a[x] = y;
            }
        }
        else
        {
            cin >> k;
            cout << query(k) << '\n';
        }
    }
    return 0;
}
