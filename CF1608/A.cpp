#include <bits/stdc++.h>
using namespace std;

int main()
{
	int T;
	scanf("%d", &T);
	while (T--)
	{
		int n;
		scanf("%d", &n);
		for (int i = 1; i <= n; i++)
			printf("%d ", i + 1);
		putchar('\n');
	}
	return 0;
}