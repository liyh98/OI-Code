/*
 * @Author: Yuhao.Li
 * @Date: 2022-02-20 14:38:45
 * @Last Modified by: Yuhao.Li
 * @Last Modified time: 2022-02-20 14:45:04
 */
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
        int n;
        cin >> n;
        for (int i = 1; i <= n; i++)
            cin >> a[i];
        int pre = -1, ans = 0;
        for (int i = 2; i < n; i++)
        {
            if (a[i] > a[i - 1] && a[i] > a[i + 1])
            {
                if (i - pre == 2)
                {
                    a[i - 1] = max(a[i], a[i - 2]);
                    pre = -1;
                }
                else
                {
                    if (pre > 0)
                        a[pre] = max(a[pre - 1], a[pre + 1]);
                    ans++;
                    pre = i;
                }
            }
        }
        if (pre > 0)
            a[pre] = max(a[pre - 1], a[pre + 1]);
        cout << ans << '\n';
        for (int i = 1; i <= n; i++)
            cout << a[i] << ' ';
        cout << '\n';
    }
    return 0;
}
