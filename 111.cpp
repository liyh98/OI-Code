#include <cstdio>
#include <algorithm>
#include <climits>
using namespace std;

long long a[100001], f[100001];
int main()
{
	int n, sum = 0;
	scanf("%d", &n);
	if (n == 1)
	{
		printf("0");
		return 0;
	}
	for (int i = 1; i <= n; i++)
	{
		scanf("%lld", &a[i]);
		a[i] += a[i - 1];
	}
	f[n] = a[n];
	long long ma = f[n];
	for (int i = n - 1; i >= 2; i--)
	{
		f[i] = a[i] - ma;
		ma = max(ma, f[i]);
	}
	printf("%lld", ma);
	return 0;
}