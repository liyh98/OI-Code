#include <bits/stdc++.h>
using namespace std;

int a[200001];
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int T;
    cin >> T;
    while (T--)
    {
        int n, k;
        cin >> n >> k;
        vector<int> cnt(n + 1);
        for (int i = 1; i <= n; i++)
            cin >> a[i], cnt[a[i]]++;
        for (int i = 1; i <= n; i++)
            cnt[i] += cnt[i - 1];
        int ans = n, ansi = 1, ansj = n;
        for (int i = 1, j = 1; i <= n; i++)
        {
            while (j <= n && cnt[j] - cnt[i - 1] < (n + k + 1) >> 1)
                j++;
            if (j > n)
                break;
            if (ans > j - i)
            {
                ans = j - i;
                ansi = i;
                ansj = j;
            }
        }
        cout << ansi << ' ' << ansj << '\n';
        for (int i = 1, pre = 0, s = 0, c = 0; i <= n; i++)
        {
            if (a[i] >= ansi && a[i] <= ansj)
                s++;
            else
                s--;
            if (s > 0)
            {
                if (++c < k)
                {
                    cout << pre + 1 << ' ' << i << '\n';
                    pre = i;
                    s = 0;
                }
                else
                {
                    cout << pre + 1 << ' ' << n << '\n';
                    break;
                }
            }
        }
    }
    return 0;
}
