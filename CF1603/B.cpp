#include <bits/stdc++.h>
using namespace std;

inline void TC()
{
	int x, y;
	scanf("%d%d", &x, &y);
	if (x == y)
		printf("%d\n", x);
	else if (x > y)
		printf("%d\n", x + y);
	else
		printf("%d\n", y - (y % x) / 2);
}

int main()
{
	int T;
	scanf("%d", &T);
	while (T--)
		TC();
	return 0;
}