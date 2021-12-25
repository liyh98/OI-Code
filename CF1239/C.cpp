#include <bits/stdc++.h>
using namespace std;

deque<int> actual_q;
priority_queue<int, vector<int>, greater<int>> q;
priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> seats;

long long ans[100001];

int main()
{
    int n, p;
    scanf("%d%d", &n, &p);
    for (int i = 1; i <= n; i++)
    {
        int x;
        scanf("%d", &x);
        seats.emplace(x, i);
    }
    long long fin = 0;
    int u = n + 1;
    while (!actual_q.empty() || !q.empty() || !seats.empty())
    {
        if (!q.empty() && (q.top() < u && (actual_q.empty() || q.top() < actual_q.back())))
        {
            actual_q.push_back(q.top());
            q.pop();
        }
        else if (!seats.empty() && fin >= seats.top().first)
        {
            q.push(seats.top().second);
            seats.pop();
        }
        else if (!actual_q.empty())
        {
            fin += p;
            u = actual_q.front();
            ans[u] = fin;
            actual_q.pop_front();
        }
        else if (u == n + 1)
            fin = seats.top().first;
        else
            u = n + 1;
    }
    for (int i = 1; i <= n; i++)
        printf("%lld ", ans[i]);
    return 0;
}