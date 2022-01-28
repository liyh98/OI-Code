#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    long long k;
    cin >> k;
    string s;
    while (k)
    {
        s = (k & 1 ? '2' : '0') + s;
        k >>= 1;
    }
    cout << s;
    return 0;
}
