#include <bits/stdc++.h>
using namespace std;

int n, ans = 0;
vector<int> a[100];
long long x;

void dfs(int step, long long now = 1)
{
    if (step > n)
    {
        if (now == x)
            ans++;
        return;
    }
    for (int &num : a[step])
    {
        if (x / now >= num && !(x % (now * num)))
            dfs(step + 1, now * num);
    }
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n >> x;
    for (int i = 1; i <= n; i++)
    {
        int l;
        cin >> l;
        a[i].resize(l);
        for (int &x : a[i])
            cin >> x;
    }
    dfs(1);
    cout << ans;
    return 0;
}
