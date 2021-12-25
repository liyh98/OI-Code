#include <cstdio>
#include <algorithm>
#include <climits>
using namespace std;

int a[100001], f[100001];
int main()
{
	int n, sum = 0;
	scanf("%d", &n);
	for (int i = 1; i <= n; i++)
	{
		scanf("%d", &a[i]);
		a[i] += a[i - 1];
	}
	int ma = 0;
	for (int i = n; i >= 2; i--)
	{
		f[i] = a[i] - ma;
		ma = max(ma, f[i]);
	}
	printf("%d", ma);
	return 0;
}