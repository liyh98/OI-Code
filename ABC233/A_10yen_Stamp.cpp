#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int x, y;
    cin >> x >> y;
    cout << (x >= y ? 0 : (y - x - 1) / 10 + 1);
    return 0;
}
