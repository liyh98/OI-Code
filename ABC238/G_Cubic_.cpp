#include <bits/stdc++.h>
using namespace std;

bool v[1000001];
vector<int> p;
int hs[1000001][3], lst[1000001], pre[1000001], sxhs[200001], cnt[1000001];

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int n, q;
    cin >> n >> q;
    mt19937 mt_rand(time(0));
    for (int i = 2; i <= 1000000; i++)
    {
        if (!v[i])
        {
            p.push_back(i);
            while (!hs[i][1])
                hs[i][1] = mt_rand();
            while (!hs[i][2] || hs[i][2] == hs[i][1])
                hs[i][2] = mt_rand();
            hs[i][0] = hs[i][1] ^ hs[i][2];
            lst[i] = i;
        }
        for (int &j : p)
        {
            if (j > 1000000 / i)
                break;
            v[i * j] = 1;
            lst[i * j] = j;
            pre[i * j] = i;
            if (i % j == 0)
                break;
        }
    }
    for (int i = 1; i <= n; i++)
    {
        int x;
        cin >> x;
        sxhs[i] = sxhs[i - 1];
        while (x)
        {
            sxhs[i] ^= hs[lst[x]][(++cnt[lst[x]]) % 3];
            x = pre[x];
        }
    }
    while (q--)
    {
        int l, r;
        cin >> l >> r;
        puts(sxhs[l - 1] == sxhs[r] ? "Yes" : "No");
    }
    return 0;
}
