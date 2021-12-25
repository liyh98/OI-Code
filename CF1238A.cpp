#include <bits/stdc++.h>
using namespace std;

int main() {
    int t;
    scanf("%d", &t);
    while (t--) {
        long long x, y;
        scanf("%lld%lld", &x, &y);
        puts(x - y > 1 ? "YES" : "NO");
    }
    return 0;
}