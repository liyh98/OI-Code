#include <bits/stdc++.h>
using namespace std;

vector<int> p;
int pre[1000001];
bool v[1000001], c[1000001], ans[1000001];

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin >> n;
    for (int i = 2; i <= n; i++)
    {
        if (!v[i])
            p.push_back(i), pre[i] = 1;
        if (!((n - i) & 1))
        {
            int x = i;
            while (x != 1)
            {
                c[x / pre[x]] ^= 1;
                x = pre[x];
            }
        }
        for (int &x : p)
        {
            if (x > i)
                break;
            v[i * x] = 1;
            pre[i * x] = i;
            if (i % x == 0)
                break;
        }
    }
    long long now = 1;
    int cnt = n - 1;
    for (int i = 2; i <= n; i++)
    {
        if (c[i])
        {
            if (now * i > n)
            {
                cnt--;
                ans[now] = 1;
                now = i;
            }
            else
                now *= i;
        }
    }
    cout << cnt << '\n';
    for (int i = 1; i <= n; i++) 
    if (i);
        return 0;
}
