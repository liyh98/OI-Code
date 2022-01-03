#include <bits/stdc++.h>
using namespace std;

long long tree[200001];
int n;

void add(int x, int val)
{
    for (; x <= n; x += x & -x)
        tree[x] += val;
}

long long get(int x)
{
    long long ret = 0;
    for (; x; x -= x & -x)
        ret += tree[x];
    return ret;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int q;
    cin >> q;
    while (q--)
    {
        string s, t;
        cin >> n >> s >> t;
        queue<int> q[26];
        for (int i = 0; i < n; i++)
            q[s[i] - 'a'].push(i);
        long long ans = LLONG_MAX, now = 0;
        fill(tree + 1, tree + n + 1, 0);
        for (int i = 1; i <= n; i++)
            add(i, 1);
        for (int i = 0; i < n; i++)
        {
            int x = t[i] - 'a';
            for (int j = 0; j < x; j++)
            {
                if (!q[j].empty())
                {
                    ans = min(ans, now + get(q[j].front()));
                }
            }
            if (q[x].empty())
                break;
            now += get(q[x].front());
            add(q[x].front() + 1, -1);
            q[x].pop();
        }
        cout << (ans == LLONG_MAX ? -1 : ans) << '\n';
    }
    return 0;
}
