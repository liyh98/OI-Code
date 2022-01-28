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
        cin >> n;
        vector<string> s(n);
        for (string &x : s)
            cin >> x;
        bool ans = 0;
        unordered_set<string> dic2, dic3;
        for (string &x : s)
        {
            int n = x.length();
            if (n == 1)
            {
                ans = 1;
                break;
            }
            if (n == 2)
            {
                if (x[0] == x[1] || dic2.find(x) != dic2.end() || dic3.find(x) != dic3.end())
                {
                    ans = 1;
                    break;
                }
                dic2.insert(string{x[1], x[0]});
            }
            if (n == 3)
            {
                if (x[0] == x[2] || dic3.find(x) != dic3.end() || dic2.find(x.substr(1, 2)) != dic2.end())
                {
                    ans = 1;
                    break;
                }
                dic3.insert(string{x[1], x[0]});
                dic3.insert(string{x[2], x[1], x[0]});
            }
        }
        cout << (ans ? "YES\n" : "NO\n");
    }
    return 0;
}
