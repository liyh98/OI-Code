#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    vector<int> p{1, 2, 3, 4, 5, 6, 7, 8};
    do
    {
        vector<int> lis(8, 1), lds(8, 1);
        int ans1 = 0, ans2 = 0;
        for (int i = 0; i < 8; i++)
        {
            for (int j = 0; j < i; j++)
            {
                if (p[i] > p[j])
                    lis[i] = max(lis[i], lis[j] + 1);
                else
                    lds[i] = max(lds[i], lds[j] + 1);
            }
            ans1 = max(ans1, lis[i]);
            ans2 = max(ans2, lds[i]);
        }
        if (ans1 == ans2)
        {
            for (int x : p)
                cout << x << ' ';
            cout << '\n';
            break;
        }
    } while (next_permutation(p.begin(), p.end()));
    return 0;
}
