#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int n, now = 0;
    cin >> n;
    vector<int> a(1);
    for (int i = 1; i <= n; i++)
    {
        int x;
        cin >> x;
        (now += x) %= 360;
        a.push_back(now);
    }
    sort(a.begin(), a.end());
    int ans = a.front() + 360 - a.back();
    for (int i = 1; i < a.size(); i++)
        ans = max(ans, a[i] - a[i - 1]);
    cout << ans;
    return 0;
}