#include <bits/stdc++.h>
using namespace std;

int a[501];
bool v[501];

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
        unordered_map<int, int> cnt;
        for (int i = 1; i <= n; i++)
            cin >> a[i], cnt[a[i]]++, v[i] = 0;
        bool flag = 1;
        for (auto &[f, s] : cnt)
            if (s & 1)
                flag = 0;
        if (!flag)
        {
            cout << "-1\n";
            continue;
        }
        vector<pair<int, int>> ins;
        vector<int> div;
        int now = 0;
        for (int i = 1; i <= n; i++)
        {
            if (v[i])
                continue;
            int nex = i + 1, c = 0;
            while (v[nex] || a[nex] != a[i])
                c += !v[nex], nex++;
            for (int j = i + 1, t = now + c + 2; j < nex; j++)
            {
                if (v[j])
                    continue;
                ins.emplace_back(t, a[j]);
                t++;
            }
            div.push_back((c + 1) << 1);
            now += (c + 1) << 1;
            v[nex] = 1;
            int l = i + 1, r = nex - 1;
            while (l < r)
            {
                while (l < r && v[l])
                    l++;
                while (l < r && v[r])
                    r--;
                if (l >= r)
                    break;
                swap(a[l++], a[r--]);
            }
        }
        cout << ins.size() << '\n';
        for (auto &[p, c] : ins)
            cout << p << ' ' << c << '\n';
        cout << div.size() << '\n';
        for (int &d : div)
            cout << d << ' ';
        cout << '\n';
    }
    return 0;
}
