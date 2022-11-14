/*
 * @Author: Yuhao.Li
 * @Date: 2022-02-20 14:36:45
 * @Last Modified by:   Yuhao.Li
 * @Last Modified time: 2022-02-20 14:36:45
 */
#include <bits/stdc++.h>
using namespace std;

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
        int ans = 0;
        while (n--)
        {
            int x;
            cin >> x;
            ans |= x;
        }
        cout << ans << '\n';
    }
    return 0;
}
