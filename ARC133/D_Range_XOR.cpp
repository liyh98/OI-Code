#include <bits/stdc++.h>
using namespace std;

#define MOD 998244353

long long V;

long long f[61][2][2];

inline long long get(int lb, int rb, long long L, long long R)
{
    memset(f, 0, sizeof f);
    f[60][1][1] = 1;
    for (int b = 59; b >= 0; b--)
    {
        for (int leq = 0; leq < 2; leq++)
            for (int req = 0; req < 2; req++)
            {
                if (!f[b + 1][leq][req])
                    continue;
                // cout << b << '\n';
                if (b == 0)
                {
                    if (leq && lb > (L & 1))
                        continue;
                    if (req && rb > (R & 1))
                        continue;
                    (f[0][leq && lb == (L & 1)][req && rb == (R & 1)] += f[1][leq][req]) %= MOD;
                }
                else
                {
                    for (int i = 0; i <= (!leq | ((L >> b) & 1)); i++)
                        for (int j = 0; j <= (!req | ((R >> b) & 1)); j++)
                        {
                            if ((i & !lb) ^ (j & !rb) != ((V >> b) & 1))
                                continue;
                            if (b == 1 && (i ^ lb ^ j ^ rb) != (V & 1))
                                continue;
                            (f[b][leq && i == ((L >> b) & 1)][req && j == ((R >> b) & 1)] += f[b + 1][leq][req]) %= MOD;
                        }
                }
            }
    }
    long long ret = 0;
    for (int leq = 0; leq < 2; leq++)
        for (int req = 0; req < 2; req++)
            ret += f[0][leq][req];
    return ret % MOD;
}

inline long long work(long long L, long long R)
{
    if (L < 0)
        return 0;
    long long ret = 0;
    for (int i = 0; i < 2; i++)
        for (int j = 0; j < 2; j++)
        {
            ret += get(i, j, L, R);
        }
    return ret % MOD;
}

int main()
{
    // ios::sync_with_stdio(false);
    // cin.tie(NULL);
    long long L, R;
    cin >> L >> R >> V;
    long long ans = (work(R, R) - work(L - 1, R) * 2 + work(L - 1, L - 1)) % MOD;
    // cout << get(0, 1, 2, 3) << '\n';
    if (!V)
        ans = (ans - R + L - 1) % MOD;
    ans = ans * ((1 + MOD) / 2) % MOD;
    ans = (ans + work(L - 1, R) - work(L - 2, R) - work(L - 1, L - 1) + work(L - 2, L - 1)) % MOD;
    if (ans < 0)
        ans += MOD;
    cout << ans;
    return 0;
}
