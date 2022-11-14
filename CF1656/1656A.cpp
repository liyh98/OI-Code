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
        for (int i = 1; i <= n; i++)
        {
            cin >> a[i];
        }
        int mi = 1, ma = 1;
        for (int i = 1; i <= n; i++)
        {
            if (a[i] < a[mi])
                mi = i;
            if (a[i] > a[ma])
                ma = i;
        }
        cout << mi << ' ' << ma << '\n';
    }
    return 0;
}
