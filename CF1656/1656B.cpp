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
        int n, k;
        cin >> n >> k;
        vector<int> a(n);
        for (auto &x : a)
            cin >> x;
        sort(a.begin(), a.end());
        bool ans = 0;
        for (int i = 0, j = 0; i < n; i++)
        {
            while (a[i] - a[j] > k)
                j++;
            if (a[i] - a[j] == k)
                ans = 1;
        }
        puts(ans ? "YES" : "NO");
    }
    return 0;
}
