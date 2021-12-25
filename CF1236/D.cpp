#include <bits/stdc++.h>
using namespace std;

vector<int> R[100001], C[100001];
int main()
{
    int n, m, k;
    scanf("%d%d%d", &n, &m, &k);
    for (int i = 1; i <= k; i++)
    {
        int x, y;
        scanf("%d%d", &x, &y);
        R[x].push_back(y);
        C[y].push_back(x);
    }
    for (int i = 1; i <= n; i++)
        sort(R[i].begin(), R[i].end());
    for (int i = 1; i <= m; i++)
        sort(C[i].begin(), C[i].end());
    int u = 1, d = n, l = 1, r = m;
    while (u < d && l < r)
    {
        auto it = lower_bound(R[u].begin(), R[u].end(), l);
        if (it != R[u].end() && *it <= r)
        {
            int nr = *it;
            for (int i = nr; i <= r; i++)
            {
                int pos = lower_bound(C[i].begin(), C[i].end(), u) - C[i].begin();
                for (int j = u; j <= d; j++)
                {
                    if (C[i].size() <= pos + j - u || C[i][pos + j - u] != j)
                    {
                        puts("No");
                        return 0;
                    }
                }
            }
            r = nr - 1;
        }
        if (l > r)
            break;
        u++;
        it = lower_bound(C[r].begin(), C[r].end(), u);
        if (it != C[r].end() && *it <= d)
        {
            int nd = *it;
            for (int i = nd; i <= d; i++)
            {
                int pos = lower_bound(R[i].begin(), R[i].end(), l) - R[i].begin();
                for (int j = l; j <= r; j++)
                {
                    if (R[i].size() <= pos + j - l || R[i][pos + j - l] != j)
                    {
                        puts("No");
                        return 0;
                    }
                }
            }
            d = nd - 1;
        }
        if (u > d)
            break;
        r--;
        it = lower_bound(R[d].begin(), R[d].end(), l);
        if (it != R[d].end() && *it <= r)
        {
            auto it = upper_bound(R[d].begin(), R[d].end(), r);
            int nl = *(--it);
            for (int i = l; i <= nl; i++)
            {
                int pos = lower_bound(C[i].begin(), C[i].end(), u) - C[i].begin();
                for (int j = u; j <= d; j++)
                {
                    if (C[i].size() <= pos + j - u || C[i][pos + j - u] != j)
                    {
                        puts("No");
                        return 0;
                    }
                }
            }
            l = nl + 1;
        }
        if (l > r)
            break;
        d--;
        it = lower_bound(C[l].begin(), C[l].end(), u);
        if (it != C[l].end() && *it <= d)
        {
            auto it = upper_bound(C[l].begin(), C[l].end(), d);
            int nu = *(--it);
            for (int i = u; i <= nu; i++)
            {
                int pos = lower_bound(R[i].begin(), R[i].end(), l) - R[i].begin();
                for (int j = l; j <= r; j++)
                {
                    if (R[i].size() <= pos + j - l || R[i][pos + j - l] != j)
                    {
                        puts("No");
                        return 0;
                    }
                }
            }
            u = nu + 1;
        }
        if (u > d)
            break;
        l++;
    }
    puts("Yes");
    return 0;
}