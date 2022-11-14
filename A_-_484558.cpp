#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

#define conv(a) (a > 9 ? 'A' + a - 10 : '0' + a)
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin >> n;
    int a = n >> 4, b = n & 15;
    string ans{(char)conv(a), (char)conv(b)};
    cout << ans << '\n';
    return 0;
}
