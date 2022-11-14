#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int T;
    cin >> T;
    while (T--)
    {
        int n;
        cin >> n;
        string s;
        cin >> s;
        int l = 0, c = 0;
        for (; l < n - 1;)
        {
            if (s[l] == '(')
            {
                ++c;
                l += 2;
            }
            else
            {
                int r = l + 1;
                while (r < n && s[r] == '(')
                    ++r;
                if (r == n)
                    break;
                ++c;
                l = r + 1;
            }
        }
        cout << c << ' ' << n - l << '\n';
    }
    return 0;
}
