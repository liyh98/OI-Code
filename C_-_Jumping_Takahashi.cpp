#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int n, x;
    cin >> n >> x;
    vector<bool> f(x + 1);
    f[0] = 1;
    for (int i = 1; i <= n; i++)
    {
        vector<bool> nf(x + 1);
        int a, b;
        cin >> a >> b;
        for (int i = a; i <= x; i++)
            nf[i] = nf[i] | f[i - a];
        for (int i = b; i <= x; i++)
            nf[i] = nf[i] | f[i - b];
        f = nf;
    }
    puts(f[x] ? "Yes" : "No");
    return 0;
}
