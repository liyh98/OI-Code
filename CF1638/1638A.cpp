#include <bits/stdc++.h>
using namespace std;

int p[501];
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
        for (int i = 1; i <= n; i++)
            cin >> p[i];
        for (int i = 1; i <= n; i++)
        {
            int mi = i;
            for (int j = i + 1; j <= n; j++)
                if (p[mi] > p[j])
                    mi = j;
            if (mi > i)
            {
                for (int j = i; j + j < i + mi; j++)
                    swap(p[j], p[i + mi - j]);
                break;
            }
        }
        for (int i = 1; i <= n; i++)
            cout << p[i] << ' ';
        cout << '\n';
    }
    return 0;
}
