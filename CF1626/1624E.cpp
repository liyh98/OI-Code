#include <bits/stdc++.h>
using namespace std;

bool f[1001];
pair<int, int> used[1001];
int pre[1001];

void print(int m, int cnt = 0)
{
    if (!m)
    {
        cout << cnt << '\n';
        return;
    }
    print(pre[m], cnt + 1);
    cout << used[m].second + 1 << ' ' << used[m].second + m - pre[m] << ' ' << used[m].first << '\n';
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int T;
    cin >> T;
    while (T--)
    {
        int n, m;
        cin >> n >> m;
        string s;
        vector<pair<int, int>> mp2(100), mp3(1000);
        for (int i = 1; i <= n; i++)
        {
            cin >> s;
            for (int j = 0; j < m - 1; j++)
            {
                int t = (s[j] - '0') * 10 + s[j + 1] - '0';
                if (!mp2[t].first)
                    mp2[t] = make_pair(i, j);
            }
            for (int j = 0; j < m - 2; j++)
            {
                int t = (s[j] - '0') * 100 + (s[j + 1] - '0') * 10 + s[j + 2] - '0';
                if (!mp3[t].first)
                    mp3[t] = make_pair(i, j);
            }
        }
        cin >> s;
        memset(f, 0, sizeof f);
        f[0] = 1;
        for (int i = 2; i <= m; i++)
        {
            if (f[i - 2])
            {
                int t = (s[i - 2] - '0') * 10 + s[i - 1] - '0';
                if (mp2[t].first)
                {
                    f[i] = 1;
                    pre[i] = i - 2;
                    used[i] = mp2[t];
                    continue;
                }
            }
            if (i > 2 && f[i - 3])
            {
                int t = (s[i - 3] - '0') * 100 + (s[i - 2] - '0') * 10 + s[i - 1] - '0';
                if (mp3[t].first)
                {
                    f[i] = 1;
                    pre[i] = i - 3;
                    used[i] = mp3[t];
                }
            }
        }
        if (!f[m])
            cout << "-1\n";
        else
            print(m);
    }
    return 0;
}
