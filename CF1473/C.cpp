#include <bits/stdc++.h>
using namespace std;

int main()
{
	int T;
	scanf("%d", &T);
	while (T--)
	{
		int n, k;
		scanf("%d%d", &n, &k);
		for (int i = 1; i < k - (n - k); i++)
			printf("%d ", i);
		for (int i = k - (n - k); i <= k; i++)
			printf("%d ", k * 3 - n - i);
		putchar('\n');
	}
	return 0;
}