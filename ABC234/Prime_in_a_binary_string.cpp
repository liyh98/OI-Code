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
        string s;
        cin >> s;
        bool flag = 0;
        for (int i = 0; i < s.length() - 1; i++)
            if (s[i] == '1')
            {
                flag = 1;
                break;
            }
        puts(flag ? "Yes" : "No");
    }
    return 0;
}
