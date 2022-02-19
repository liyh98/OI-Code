#include <bits/stdc++.h>
using namespace std;

int a[100001];

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
        bool flag = 1;
        for (int i = 1; i <= n; i++)
            cin >> a[i];
        int l[2] = {0, 0};
        for (int i = 1; i <= n; i++)
        {
            auto &s = l[a[i] & 1];
            if (s > a[i])
            {
                flag = 0;
                break;
            }
            s = a[i];
        }
        puts(flag ? "Yes" : "No");
    }
    return 0;
}
