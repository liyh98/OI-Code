#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
typedef long long ll;

#define output_invalid cout << '-' << '1' << '\n'
void TC()
{
    int p, a, b, s, g;
    cin >> p >> a >> b >> s >> g;
    if (s == g)
    {
        cout << '0' << '\n';
        return;
    }
    atcoder::modint::set_mod(p);
    atcoder::modint A(a), B(b), S(s), G(g);
    if (a == 1)
    {
        if (b == 0)
            output_invalid;
        else
        {
            atcoder::modint ans = (G - S) / B;
            cout << ans.val() << '\n';
        }
    }
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int T;
    cin >> T;
    while (T--)
        TC();
    return 0;
}
