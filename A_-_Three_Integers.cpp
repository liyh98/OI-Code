#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    ll a, b, c;
    cin >> a >> b >> c;
    if (a > b)
        swap(a, b);
    if (b > c)
        swap(b, c);
    if (a > b)
        swap(a, b);
    ll x = c - b, y = c - a, z = c - x - y;
    if (x >= 0 && y >= 0 && z >= 0)
        cout << c;
    else
        cout << -1;
    return 0;
}
