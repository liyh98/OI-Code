#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int x;
    int ans = 0;
    cin >> x;
    ans += x;
    x = (x % 100) * 10 + (x / 100);
    ans += x;
    x = (x % 100) * 10 + (x / 100);
    ans += x;
    cout << ans;
    return 0;
}
