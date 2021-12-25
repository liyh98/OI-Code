#include <bits/stdc++.h>
using namespace std;

unordered_map<string, int> s;
int main()
{
    int n;
    cin >> n;
    while (n--)
    {
        string st;
        cin >> st;
        s[st]++;
    }
    vector<pair<int, string>> v;
    for (auto p : s)
        v.emplace_back(p.second, p.first);
    sort(v.begin(), v.end());
    cout << v.back().second;
}