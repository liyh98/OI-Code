#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin >> n;
    unordered_set<int> s;
    while (n--)
    {
        int x;
        cin >> x;
        s.insert(x);
    }
    cout << s.size();
    return 0;
}
