#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int l, r;
    string s;
    cin >> l >> r >> s;
    for (int i = 0; i < l - 1; i++)
        cout << s[i];
    for (int i = l - 1; i < r; i++)
        cout << s[l + r - 2 - i];
    for (int i = r; i < s.length(); i++)
        cout << s[i];
    return 0;
}
