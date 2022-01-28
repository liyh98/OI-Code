#include <bits/stdc++.h>
using namespace std;

int a[200001];

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    int val = 0;
    for (int i = 1; i < n; i++)
    {
        if (a[i] > a[i + 1])
        {
            val = a[i];
            break;
        }
    }
    if (!val)
        val = a[n];
    for (int i = 1; i <= n; i++)
    {
        if (a[i] != val)
            cout << a[i] << ' ';
    }
    return 0;
}
