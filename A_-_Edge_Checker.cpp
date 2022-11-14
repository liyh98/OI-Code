#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int x, y;
    cin >> x >> y;
    puts(abs(x - y) == 1 || abs(x - y) == 9 ? "Yes" : "No");
    return 0;
}
