#include <bits/stdc++.h>
using namespace std;

set<int> position[26];

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    string s;
    cin >> n >> s;
    for (int i = 0; i < n; i++)
    {
        position[s[i] - 'a'].insert(i);
    }
    int l = 0, r = n;
    for (int i = 0; i < 26; i++)
    {
        while (l < r && s[l] - 'a' == i)
            ++l;
        if (l >= r)
            break;
        auto it = position[i].lower_bound(r);
        if (it == position[i].begin())
            continue;
        --it;
        while (*it > l)
        {
            swap(s[l], s[*it]);
            while (l < r && s[l] - 'a' == i)
                ++l;
            r = *it;
            if (it == position[i].begin())
                break;
            if (l >= r)
                break;
            --it;
        }
    }
    cout << s;
    return 0;
}
