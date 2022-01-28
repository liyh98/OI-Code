#include <bits/stdc++.h>
using namespace std;

int a[5];
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
        for (int i = 0; i < 4; i++)
            a[i] = i;
        a[4] = 20;
        while (n--)
        {
            int ans = 0;
            for (int i = 0; i < 4; i++)
                ans |= 1 << a[i];
            cout << ans << ' ';
            for (int i = 0; i < 4; i++)
            {
                if (a[i] < a[i + 1] - 1)
                {
                    a[i]++;
                    for (int j = 0; j < i; j++)
                        a[j] = j;
                    break;
                }
            }
        }
        cout << '\n';
    }
    return 0;
}
