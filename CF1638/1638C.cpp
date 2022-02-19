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
        stack<int> st;
        for (int i = 1; i <= n; i++)
        {
            int x;
            cin >> x;
            int best = max(x, st.empty() ? 0 : st.top());
            while (!st.empty() && st.top() > x)
            {
                st.pop();
            }
            st.push(best);
        }
        cout << st.size() << '\n';
    }
    return 0;
}
