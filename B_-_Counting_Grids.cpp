#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
typedef long long ll;

typedef atcoder::modint998244353 mint;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin >> n;
    mint ans = n * n, tot = 1;
    for (int i = 1; i <= n * n; i++)
        ans *= i;
    for (int i = 1; i < (n << 1); i++)
        ans /= i;
    for (int i = 1; i <= (n * n - n - n + 1); i++)
        ans /= i;
    for (int i = 1; i < n; i++)
        ans *= i * i;
    for (int i = 1; i <= (n - 1) * (n - 1); i++)
        ans *= i;
    for (int i = 1; i <= n * n; i++)
        tot *= i;
    ans = tot - ans;
    cout << ans.val();
    return 0;
}
