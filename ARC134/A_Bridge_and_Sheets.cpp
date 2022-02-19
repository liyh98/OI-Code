#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int N;
    long long L, W;
    cin >> N >> L >> W;
    vector<long long> a(N);
    for (auto &x : a)
        cin >> x;
    sort(a.begin(), a.end());
    long long pre = 0, ans = 0;
    for (auto &x : a)
    {
        if (x > pre)
            ans += (x - pre - 1) / W + 1;
        pre = x + W;
    }
    if (L > pre)
        ans += (L - pre - 1) / W + 1;
    cout << ans;
    return 0;
}
