#include <bits/stdc++.h>
using namespace std;

bool v[1000000];
int dis[1000000];
const int pow10[] = {1, 10, 100, 1000, 10000, 100000, 1000000};

int rotateX(int x)
{
    int ret = x / 10;
    ret += x % 10 * pow10[(int)floor(log10(x))];
    return ret;
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int a, n;
    cin >> a >> n;
    int l = pow10[(int)ceil(log10(n))] / a;
    queue<int> q;
    q.push(1);
    v[1] = 1;
    dis[n] = -1;
    while (!q.empty())
    {
        int x = q.front();
        q.pop();
        if (x <= l && !v[x * a])
        {
            v[x * a] = 1;
            dis[x * a] = dis[x] + 1;
            q.push(x * a);
        }
        if (x > 10 && x % 10)
        {
            int r = rotateX(x);
            if (v[r])
                continue;
            v[r] = 1;
            dis[r] = dis[x] + 1;
            q.push(r);
        }
    }
    cout << dis[n];
    return 0;
}
