#include <bits/stdc++.h>
using namespace std;

vector<int> e[100001];
bool v[100001], flag;

void dfs(int x, int pre)
{
    v[x] = 1;
    if (e[x].size() > 2)
        flag = 1;
    for (int &nex : e[x])
    {
        if (!v[nex])
            dfs(nex, x);
        else if (nex != pre)
            flag = 1;
    }
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int n, m;
    cin >> n >> m;
    while (m--)
    {
        int x, y;
        cin >> x >> y;
        e[x].push_back(y);
        e[y].push_back(x);
    }
    for (int i = 1; i <= n && !flag; i++)
    {
        if (!v[i])
            dfs(i, 0);
    }
    puts(flag ? "No" : "Yes");
    return 0;
}
