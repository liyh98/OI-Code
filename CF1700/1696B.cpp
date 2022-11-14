#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int T;
    cin >> T;
    while (T--)
    {
        int n, cnt = 0;
        cin >> n;
        int pre = 0;
        while (n--)
        {
            int x;
            cin >> x;
            if (x && !pre)
                cnt++;
            pre = x;
        }
        cout << min(cnt, 2) << '\n';
    }
    return 0;
}
