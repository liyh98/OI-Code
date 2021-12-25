#include <bits/stdc++.h>
using namespace std;

char s[102];
int a[101];

inline void TC()
{
    scanf("%s", s + 1);
    int n = strlen(s + 1);
    for (int i = 1; i <= n; i++) a[i] = s[i] - '0';
    string ans;
    for (int i = 1; i <= n; i++) {
        if (a[i - 1] < a[i]) {
            for (int j = 1; j <= a[i] - a[i - 1]; j++) ans += '(';
        }
        if (a[i - 1] > a[i]) {
            for (int j = 1; j <= a[i - 1] - a[i]; j++) ans += ')';
        }
        ans += '0' ^ a[i];
    }
    for (int i = 1; i <= a[n]; i++) ans += ')';
    cout << ans << '\n';
}

int main()
{
    int T;
    scanf("%d", &T);
    for (int i = 1; i <= T; i++)
    {
        printf("Case #%d: ", i);
        TC();
    }
    return 0;
}