#include <bits/stdc++.h>
using namespace std;

char s[5001];
int f[5001][5001];

int main() {
    scanf("%s", s + 1);
    int n = strlen(s + 1);
    for (int i = 1; i <= n; i++) f[i][i] = 1;
    for (int i = 2; i <= n; i++) {
        for (int j = 1; j <= n - i + 1; j++) {
            f[j][j + i - 1] = max(f[j + 1][j + i - 1], f[j][j + i - 2]);
            if (s[j] == s[j + i - 1]) f[j][j + i - 1] = max(f[j][j + i - 1], f[j + 1][j + i - 2] + 2);
        }
    }
    printf("%d", f[1][n]);
}