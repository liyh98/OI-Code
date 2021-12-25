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
        long long x;
        string s;
        cin >> n >> k >> x >> s;
        x--;
        int cnt = 0;
        vector<int> lim;
        for (char c : s)
        {
            if (c == '*')
            {
                if (!lim.empty() && lim.back() != -1)
                    lim.back() += k;
                else
                    cnt++, lim.push_back(k);
            }
            else
                lim.push_back(-1);
        }
        vector<int> condensed, num(cnt);
        condensed.reserve(cnt);
        for (int x : lim)
            if (x != -1)
                condensed.push_back(x);
        for (int i = cnt - 1; i >= 0; i--)
        {
            num[i] = x % (condensed[i] + 1);
            x /= condensed[i] + 1;
        }
        int pos = 0;
        for (int x : lim)
        {
            if (x != -1)
            {
                for (int i = 0; i < num[pos]; i++)
                    putchar('b');
                pos++;
            }
            else
                putchar('a');
        }
        putchar('\n');
    }
    return 0;
}
