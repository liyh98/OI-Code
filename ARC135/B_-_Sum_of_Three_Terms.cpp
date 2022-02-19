#include <bits/stdc++.h>
using namespace std;

long long s[300001], ans[300005];

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++)
        cin >> s[i];
    for (int i = 1; i <= 3; i++)
    {
        long long now = 0;
        for (int j = i; j + 1 <= n; j += 3)
        {
            now += s[j + 1] - s[j];
            ans[i] = max(ans[i], -now);
        }
    }
    if (ans[1] + ans[2] + ans[3] > s[1])
    {
        cout << "No";
    }
    else
    {
        cout << "Yes\n";
        ans[1] = s[1] - ans[2] - ans[3];
        for (int i = 4; i <= n + 2; i++)
            ans[i] = s[i - 2] - ans[i - 2] - ans[i - 1];
        for (int i = 1; i <= n + 2; i++)
            cout << ans[i] << ' ';
    }
    return 0;
}
