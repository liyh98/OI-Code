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
        int n = s.length(), cnt = 0;
        for (char c : s)
            cnt += c == 'N';
        puts(cnt == 1 ? "NO" : "YES");
    }
    return 0;
}
