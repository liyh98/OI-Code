#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    long long k, ans = 0, now = 0;
    cin >> n >> k;
    unordered_map<long long, int> cnt;
    cnt[0] = 1;
    for (int i = 1; i <= n; i++)
    {
        int x;
        cin >> x;
        now += x;
        if (cnt.find(now - k) != cnt.end())
            ans += cnt[now - k];
        cnt[now]++;
    }
    cout << ans;
    return 0;
}
