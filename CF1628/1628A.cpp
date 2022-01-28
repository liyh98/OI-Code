#include <bits/stdc++.h>
using namespace std;

int a[200001], s[200001];
bool c[200001];
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
        memset(s, 0, sizeof s);
        memset(c, 0, sizeof c);
        for (int i = 1; i <= n; i++)
            cin >> a[i], s[a[i]]++;
        int mex = 0;
        vector<int> ans;
        for (int i = 1; i <= n; i++)
        {
            if (a[i] >= mex)
                c[a[i]] = 1;
            s[a[i]]--;
            while (c[mex])
                c[mex++] = 0;
            if (!s[mex])
            {
                ans.push_back(mex);
                mex = 0;
            }
        }
        cout << ans.size() << '\n';
        for (int &x : ans)
            cout << x << ' ';
        cout << '\n';
    }
    return 0;
}
