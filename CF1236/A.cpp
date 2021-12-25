#include <bits/stdc++.h>
using namespace std;

int main()
{
    int T;
    scanf("%d", &T);
    while (T--)
    {
        int a, b, c;
        scanf("%d%d%d", &a, &b, &c);
        int B = min(b, c / 2);
        b -= B;
        int A = min(a, b / 2);
        printf("%d\n", (A + B) * 3);
    }
    return 0;
}