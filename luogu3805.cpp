#include <bits/stdc++.h>
using namespace std;

char s[25000000];
int rad[25000000];

int main() 
{
    s[0] = '$';
    s[1] = '#';
    int n = 1;
    char c = getchar();
    while (c >= 'a' && c <= 'z') {
        s[++n] = c;
        s[++n] = '#';
        c = getchar();
    }
    int r = 0, mid = 0, ans = 0;
    for (int i = 1; i <= n; i++) {
        if (i < r) rad[i] = min(r - i, rad[mid + mid - i]);
        else rad[i] = 1;
        while (s[i - rad[i]] == s[i + rad[i]]) rad[i]++;
        if (i + rad[i] > r) mid = i, r = i + rad[i];
        ans = max(ans, rad[i]);
    }
    printf("%d", ans - 1);
    return 0;
}