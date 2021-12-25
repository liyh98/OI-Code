#include <bits/stdc++.h>
using namespace std;

multiset<int> s;
queue<int> q;

int main()
{
    int Q;
    scanf("%d", &Q);
    while (Q--)
    {
        int op, x;
        scanf("%d", &op);
        if (op == 1)
        {
            scanf("%d", &x);
            q.push(x);
        }
        else if (op == 2)
        {
            scanf("%d", &x);
            s.insert(x);
        }
        else
        {
            while (s.count(q.front()))
            {
                s.erase(s.find(q.front()));
                q.pop();
            }
            printf("%d\n", q.front());
            q.pop();
        }
    }
    return 0;
}