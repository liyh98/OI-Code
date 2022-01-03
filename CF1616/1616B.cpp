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
        int n;
        string s;
        cin >> n >> s;
        char first = s[0];
        int i;
        for (i = 0; i < n - 1; i++)
        {
            if (s[i] < s[i + 1] || (s[i] == s[i + 1] && s[i] == first))
            {
                break;
            }
        }
        for (int j = 0; j <= i; j++)
            cout << s[j];
        for (int j = i; j >= 0; j--)
            cout << s[j];
        cout << '\n';
    }
    return 0;
}
