#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void work()
{
    string s;
    cin >> s;
    int n = s.length(), smallest = 9;
    vector<int> cnt(10);
    for (int i = n - 1; i >= 0; --i)
    {
        int x = s[i] - '0';
        smallest = min(smallest, x);
        if (x > smallest)
        {
            cnt[min(x + 1, 9)]++;
        }
        else
        {
            cnt[x]++;
        }
    }
    for (int i = 0; i < 10; ++i)
    {
        while (cnt[i]--)
            putchar('0' + i);
    }
    putchar('\n');
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
    while (t--)
    {
        work();
    }
    return 0;
}
