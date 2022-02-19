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
        long long hc, dc, hm, dm, k, w, a;
        cin >> hc >> dc >> hm >> dm >> k >> w >> a;
        bool ans = 0;
        for (int i = 0; i <= k; i++)
        {
            if ((hm - 1) / (dc + w * i) <= (hc + a * (k - i) - 1) / dm)
            {
                ans = 1;
                break;
            }
        }
        puts(ans ? "YES" : "NO");
    }
    return 0;
}
