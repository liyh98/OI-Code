#include <bits/stdc++.h>
using namespace std;

inline void TC()
{
	int n, now = 9;
	scanf("%d", &n);
	if (n > 0)
		putchar('9');
	if (n > 1)
		putchar('8');
	for (int i = 3; i <= n; i++)
	{
		printf("%d", now);
		now = (now + 1) % 10;
	}
	putchar('\n');
}

int main()
{
	int T;
	scanf("%d", &T);
	while (T--)
		TC();
	return 0;
}