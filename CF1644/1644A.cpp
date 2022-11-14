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
        bool R = 0, G = 0, B = 0, ans = 1;
        for (char c : s)
        {
            if (c == 'r')
                R = 1;
            if (c == 'g')
                G = 1;
            if (c == 'b')
                B = 1;
            if (c == 'R' && !R)
            {
                ans = 0;
            }
            if (c == 'G' && !G)
            {
                ans = 0;
            }
            if (c == 'B' && !B)
            {
                ans = 0;
            }
        }
        puts(ans ? "YES" : "NO");
    }
    return 0;
}
