#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    string s, t;
    cin >> s >> t;
    int n = s.length(), d = (t[0] - s[0] + 26) % 26;
    bool flag = 1;
    for (int i = 1; i < n; i++)
    {
        if ((t[i] - s[i] + 26) % 26 != d)
        {
            flag = 0;
            break;
        }
    }
    puts(flag ? "Yes" : "No");
    return 0;
}
