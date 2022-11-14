#include <bits/stdc++.h>
using namespace std;

int a[200001];

struct custom_hash
{
    static uint64_t splitmix64(uint64_t x)
    {
        x += 0x9e3779b97f4a7c15;
        x = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9;
        x = (x ^ (x >> 27)) * 0x94d049bb133111eb;
        return x ^ (x >> 31);
    }

    size_t operator()(uint64_t x) const
    {
        static const uint64_t FIXED_RANDOM = chrono::steady_clock::now().time_since_epoch().count();
        return splitmix64(x + FIXED_RANDOM);
    }
};

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
        int c0 = 0, c1 = 0;
        for (int i = 1; i <= n; i++)
            cin >> a[i], c0 += a[i] == 0, c1 += a[i] == 1;
        if (!c1)
        {
            puts("YES");
            continue;
        }
        unordered_set<int, custom_hash> s;
        bool flag = 1;
        for (int i = 1; i <= n; i++)
        {
            if (s.count(a[i] - 1) || s.count(a[i] + 1))
                flag = 0;
            s.insert(a[i]);
        }
        puts(flag ? "YES" : "NO");
    }
    return 0;
}
