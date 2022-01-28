#include <bits/stdc++.h>
using namespace std;

int a[200001], b[200001];

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int h, w, k;
    cin >> h >> w >> k;
    int sa = 0, sb = 0;
    for (int i = 1; i <= h; i++)
    {
        cin >> a[i];
        sa = (sa + a[i]) % k;
    }
    for (int i = 1; i <= w; i++)
    {
        cin >> b[i];
        sb = (sb + b[i]) % k;
    }
    if (sa != sb)
        cout << "-1";
    else
    {
        long long r = 0, c = 0;
        int sr = (k - w % k) % k;
        for (int i = 1; i <= h; i++)
            r += (sr + k - a[i]) % k;
        int sc = (k - h % k) % k;
        for (int i = 1; i <= w; i++)
            c += (sc + k - b[i]) % k;
        long long s = k - 1;
        s = s * h * w;
        s -= max(r, c);
        cout << s;
    }
    return 0;
}