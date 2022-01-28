#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    long long x;
    cin >> x;
    vector<int> a;
    long long t = x;
    while (t)
    {
        a.push_back(t % 10);
        t /= 10;
    }
    int len = a.size();
    if (len == 1)
    {
        cout << x;
        return 0;
    }
    long long ans = LLONG_MAX;
    for (int first = a.back(); first < 10; first++)
    {
        for (int d = -(first / (len - 1)); d <= (9 - first) / (len - 1); d++)
        {
            long long now = 0;
            for (int j = len, digit = first; j; j--, digit += d)
                now = now * 10 + digit;
            if (now >= x)
                ans = min(ans, now);
        }
    }
    cout << ans;
    return 0;
}
