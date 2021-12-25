#include <bits/stdc++.h>
using namespace std;

inline void TC()
{
	long long n, k;
	scanf("%lld %lld", &n, &k);
	long long now = 1;
	long long days = 0;
	while (now < k)
	{
		days++;
		now <<= 1;
	}
	if (now >= n)
	{
		printf("%lld\n", days);
	}
	else
	{
		printf("%lld\n", days + (n - now - 1) / k + 1);
	}
}
int main()
{
	int T;
	scanf("%d", &T);
	while (T--)
		TC();
	return 0;
}