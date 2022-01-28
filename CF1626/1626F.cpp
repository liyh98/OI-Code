#include <iostream>
#include <cstring>
using namespace std;

#define MOD 998244353

int gcd(int x, int y)
{
    return x ? gcd(y % x, x) : y;
}

int prob[720720], expe[720720], nprob[720720], nexpe[720720];

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    int a0, x, y, k, M;
    cin >> n >> a0 >> x >> y >> k >> M;
    int LCM = 1;
    for (int i = 2; i < k; i++)
        LCM = LCM * i / gcd(LCM, i);
    int ans = 0;
    for (int i = 0; i < n; i++)
    {
        ans = (ans + a0 / LCM) % MOD;
        prob[a0 % LCM]++;
        a0 = ((long long)a0 * x + y) % M;
    }
    ans = (long long)ans * LCM % MOD * k % MOD;
    for (int i = 1; i < k; i++)
        ans = (long long)ans * n % MOD;
    size_t sz = sizeof(int) * LCM;
    for (int i = 1; i <= k; i++)
    {
        for (int j = 0; j < LCM; j++)
        {
            nexpe[j] = (long long)expe[j] * (n - 1) % MOD;
            nprob[j] = (long long)prob[j] * (n - 1) % MOD;
            int nj = j - j % i;
            nexpe[nj] = (nexpe[nj] + expe[j] + (long long)prob[j] * j) % MOD;
            nprob[nj] = (nprob[nj] + prob[j]) % MOD;
        }
        memcpy(expe, nexpe, sz);
        memcpy(prob, nprob, sz);
    }
    for (int i = 0; i < LCM; i++)
        ans = (ans + expe[i]) % MOD;
    cout << ans;
    return 0;
}
