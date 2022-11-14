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
        // cout << 'n' << n << '\n';
        string s;
        cin >> s;
        if (s[0] < '9')
        {
            for (int i = 0; i < n; i++)
            {
                cout << (char)('0' + '9' - s[i]);
            }
        }
        else
        {
            int borrow = 0;
            string ans;
            ans.resize(n);
            for (int i = n - 1; i >= 0; i--)
            {
                if (1 - borrow < s[i] - '0')
                {
                    ans[i] = '0' + (11 - borrow - (s[i] - '0'));
                    borrow = 1;
                }
                else
                {
                    ans[i] = '0' + (1 - borrow - (s[i] - '0'));
                    borrow = 0;
                }
            }
            cout << ans;
        }
        cout << '\n';
    }
    return 0;
}
