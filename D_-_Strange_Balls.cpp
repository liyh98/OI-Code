#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int n, d = 0;
    cin >> n;
    stack<pair<int, int>> st;
    for (int i = 1; i <= n; i++)
    {
        int a;
        cin >> a;
        if (!st.empty() && st.top().first == a)
            st.top().second++;
        else
            st.emplace(a, 1);
        if (st.top().first == st.top().second)
            d += st.top().second, st.pop();
        cout << i - d << '\n';
    }
    return 0;
}
