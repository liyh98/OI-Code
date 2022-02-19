#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int N = 1000;
    srand(time(0));
    cout << N << ' ' << N << '\n';
    for (int i = 1; i <= N; i++)
        for (int j = 1; j <= N; j++)
            cout << i << ' ';
    return 0;
}
