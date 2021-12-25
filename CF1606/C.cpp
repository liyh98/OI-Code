#include <bits/stdc++.h>
using namespace std;

int a[12];

inline void TC()
{
	int n, k;
	scanf("%d%d", &n, &k);
	k++;
	for (int i = 1; i <= n; i++)
		scanf("%d", &a[i]);
	int now = 1;
	long long ans = 0;
	for (int i = 1; i < n && k; i++)
	{
		int num = 1;
		for (int j = a[i]; j < a[i + 1]; j++)
			num *= 10;
		ans += (long long)now * min(num - 1, k);
		k -= min(num - 1, k);
		now *= num;
	}
	ans += (long long)now * k;
	printf("%lld\n", ans);
}
int main()
{
	int T;
	scanf("%d", &T);
	while (T--)
		TC();
	return 0;
}