#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int n, k;
    cin >> n >> k;
    set<int> s;
    for (int i = 1; i <= k; i++)
    {
        int x;
        cin >> x;
        s.insert(x);
    }
    cout << *s.begin() << '\n';
    for (int i = k + 1; i <= n; i++)
    {
        int x;
        cin >> x;
        s.insert(x);
        s.erase(s.begin());
        cout << *s.begin() << '\n';
    }
    return 0;
}
