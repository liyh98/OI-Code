#include <bits/stdc++.h>
using namespace std;

int p[100001];
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++)
        cin >> p[i];
    if (((p[1] + 1) % n) == (p[2] % n))
    {
        int ans = (1 + n - p[1]) % n;
        ans = min(ans, 2 + n - (1 + n - p[1]) % n);
        cout << ans;
    }
    else
    {
        int ans = (1 + n - p[n]) % n;
        ans = min(ans, n - (1 + n - p[n]) % n) + 1;
        cout << ans;
    }
    return 0;
}
