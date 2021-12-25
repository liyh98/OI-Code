#include <bits/stdc++.h>
using namespace std;

priority_queue<int> pq;
int main()
{
    int n, k, i, ans = 0, lst = INT_MAX;
    scanf("%d%d", &n, &k);
    for (i = 1; i <= k; i++)
    {
        int x;
        scanf("%d", &x);
        pq.push(x);
    }
    while (!pq.empty())
    {
        int x = pq.top();
        pq.pop();
        if (x < lst)
        {
            ans++;
            lst = x;
            if (i++ <= n)
            {
                scanf("%d", &x);
                pq.push(x);
            }
        }
    }
    printf("%d", ans);
    return 0;
}