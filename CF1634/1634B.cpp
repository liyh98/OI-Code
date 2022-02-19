#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
    while (t--)
    {
        int n, x;
        long long y;
        cin >> n >> x >> y;
        bool flag = (x & 1) ^ (y & 1);
        while (n--)
        {
            int x;
            cin >> x;
            flag ^= x & 1;
        }
        puts(flag ? "Bob" : "Alice");
    }
    return 0;
}
