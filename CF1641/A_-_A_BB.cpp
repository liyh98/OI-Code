#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    string s;
    cin >> n >> s;
    string ans;
    for (int i = 0; i < n; i++)
    {
        if (s[i] == 'A' || s[i] == 'C')
            ans += s[i];
        else if (i == n - 1 || s[i + 1] == 'C')
            ans += s[i];
        else if (s[i + 1] == 'A')
            s[i + 1] = 'B', ans += 'A';
        else
            ans += 'A', i++;
    }
    cout << ans;
    return 0;
}
