#include <bits/stdc++.h>
using namespace std;

vector<int> e[100001];
int mid;

int dfs(int x)
{
    int ans = 1, n = e[x].size();
    vector<int> t;
    for (int i = 0; i < n; i++)
        t.push_back(dfs(e[x][i]));
    sort(t.begin(), t.end(), greater<int>());
    for (int i = 0; i < mid && i < n; i++)
        ans += t[i];
    return ans;
}

inline int read()
{
    register int x = 0;
    register char ch = getchar_unlocked();
    for (; ch < '0' || ch > '9'; ch = getchar_unlocked())
        ;
    for (; ch >= '0' && ch <= '9'; ch = getchar_unlocked())
        (x *= 10) += ch ^ 48;
    return x;
}

int main()
{
    int n = read(), m = read();
    for (int i = 2; i <= n; i++)
        e[read()].push_back(i);
    int l = 0, r = n - 1, ans = n - 1;
    while (l <= r)
    {
        mid = (l + r) >> 1;
        if (dfs(1) >= m)
            ans = mid, r = mid - 1;
        else
            l = mid + 1;
    }
    printf("%d", ans);
    return 0;
}