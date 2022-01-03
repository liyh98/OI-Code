#include <bits/stdc++.h>
using namespace std;

int r[100001], c[100001];
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int n, q;
    cin >> n;
    for (int i = 1; i <= n; i++)
        cin >> r[i];
    for (int i = 1; i <= n; i++)
        cin >> c[i];
    cin >> q;
    for (int i = 1; i <= q; i++)
    {
        int x, y;
        cin >> x >> y;
        cout << (r[x] + c[y] >= n + 1 ? '#' : '.');
    }
    return 0;
}
