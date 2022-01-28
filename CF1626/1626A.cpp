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
        vector<int> c(26);
        string s;
        cin >> s;
        for (char &ch : s)
            c[ch - 'a']++;
        for (int i = 0; i < 26; i++)
            while (c[i]--)
                putchar('a' + i);
        putchar('\n');
    }
    return 0;
}
