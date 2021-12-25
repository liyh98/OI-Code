#include <bits/stdc++.h>
using namespace std;

int main()
{
	int n, sum = 0;
	scanf("%d", &n);
	for (int i = 1; i <= n; i++)
	{
		int x;
		scanf("%d", &x);
		sum += x;
	}
	printf("%d\n", sum);
	printf("%f", (long double)sum / n);
	return 0;
}