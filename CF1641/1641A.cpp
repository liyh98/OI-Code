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
        int n, x;
        cin >> n >> x;
        vector<int> a(n);
        for (int &b : a)
            cin >> b;
        sort(a.begin(), a.end());
        multiset<int> s;
        for (int &b : a)
        {
            auto it = s.find(b / x);
            if (b % x == 0 && it != s.end())
                s.erase(it);
            else
                s.insert(b);
        }
        cout << s.size() << '\n';
    }
    return 0;
}
