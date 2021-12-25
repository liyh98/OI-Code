#include <bits/stdc++.h>
using namespace std;

char s[100];
int a[51][51];
bool v[51];

int main()
{
    srand(time(0));
    for (int i = 1; i <= 100; i++)
    {
        sprintf(s, "%d.out", i);
        freopen(s, "w", stdout);
        int n = (rand() % 50) + 1, k = (rand() % (n * n + 1 - n)) + n;
        if (k == n + 1 || k == n * n - 1)
            continue;
        printf("%d %d\n", n, k);
        sprintf(s, "echo 1 %d %d | ./Indicium", n, k);
        system(s);
        fclose(stdout);
        sprintf(s, "%d.out", i);
        freopen(s, "r", stdin);
        string str;
        getline(cin, str);
        for (int j = 1; j <= n; j++)
            for (int k = 1; k <= n; k++)
                scanf("%d", &a[j][k]);
        int sum = 0;
        for (int j = 1; j <= n; j++)
            sum += a[j][j];
        if (sum != k)
            return 0;
        for (int j = 1; j <= n; j++)
        {
            memset(v, 0, sizeof v);
            for (int k = 1; k <= n; k++)
            {
                if (v[a[j][k]])
                    return 0;
                v[a[j][k]] = 1;
            }
            memset(v, 0, sizeof v);
            for (int k = 1; k <= n; k++)
            {
                if (v[a[k][j]])
                    return 0;
                v[a[k][j]] = 1;
            }
        }
    }
    return 0;
}