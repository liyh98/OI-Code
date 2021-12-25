#include <bits/stdc++.h>
using namespace std;

deque<int> l, r;

#define gu getchar_unlocked

int read()
{
    char c = gu();
    int ret = 0;
    for (; c < '0' || c > '9'; c = gu());
    for (; c >= '0' && c <= '9'; c = gu()) ret = ret * 10 + (c ^ 48);
    return ret;
}

int main()
{
    int q;
    scanf("%d", &q);
    while (q--)
    {
        int op;
        scanf("%d", &op);
        if (op == 1)
        {
            int x;
            scanf("%d", &x);
            r.push_back(x);
        }
        else swap(l, r);
        if (r.size() > l.size())
        {
            l.push_back(r.front());
            r.pop_front();
        }
    }
    while (!l.empty())
    {
        printf("%d ", l.front());
        l.pop_front();
    }
    while (!r.empty())
    {
        printf("%d ", r.front());
        r.pop_front();
    }
    return 0;
}