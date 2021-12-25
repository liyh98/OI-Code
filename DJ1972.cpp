#include <bits/stdc++.h>
using namespace std;

pair<int, int> a[200001];
priority_queue<int, vector<int>, greater<int>> pq;
int main()
{
    int T;
    scanf("%d", &T);
    while (T--)
    {
        int n, cnt = 0;
        long long ans = 0;
        while (!pq.empty())
            pq.pop();
        scanf("%d", &n);
        for (int i = 1; i <= n; i++)
            scanf("%d%d", &a[i].first, &a[i].second);
        sort(a + 1, a + n + 1);
        for (int i = n; i > 0;)
        {
            do
            {
                pq.push(a[i--].second);
            } while (a[i].first == a[i + 1].first && i > 0);
            for (int j = a[i + 1].first - i - cnt; j > 0; j--)
            {
                ans += pq.top();
                cnt++;
                pq.pop();
            }
        }
        printf("%lld\n", ans);
    }
    return 0;
}