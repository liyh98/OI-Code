#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int n, x, y;
    bool flag = 0;
    cin >> n >> x >> y;
    for (int i = 1; i <= n; i++)
    {
        int a;
        cin >> a;
        a %= x + y;
        if (a >= min(x, y) && a < max(x, y))
        {
            puts(x < y ? "First" : "Second");
            return 0;
        }
        if (a >= x)
            flag = 1;
    }
    puts(flag ? "First" : "Second");
    return 0;
}
