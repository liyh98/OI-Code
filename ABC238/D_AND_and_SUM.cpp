#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int T;
    cin >> T;
    while (T--)
    {
        long long a, s;
        cin >> a >> s;
        long long d = s - (a << 1);
        puts(d < 0 || d & a ? "No" : "Yes");
    }
    return 0;
}
