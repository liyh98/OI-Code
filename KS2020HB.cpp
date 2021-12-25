#include <bits/stdc++.h>
using namespace std;

int a[20];

inline long long calc(long long x)
{
	if (!x)
		return 0;
	int len = 0;
	while (x)
	{
		a[++len] = x % 10;
		x /= 10;
	}
	long long ret = 0, base = 1;
	for (int d = 1; d < len; d++)
	{
		base *= 5;
		ret += base;
	}
	for (int d = len; d >= 0; d--)
	{
		if (!d)
		{
			ret++;
			break;
		}
		if ((len - d) & 1)
			ret += base * ((a[d] + 1) / 2);
		else
			ret += base * (a[d] / 2);
		if (!(((len - d) & 1) ^ (a[d] & 1)))
			break;
		base /= 5;
	}
	return ret;
}

inline void TC()
{
	long long L, R;
	scanf("%lld%lld", &L, &R);
	printf("%lld\n", calc(R) - calc(L - 1));
}

int main()
{
	int T;
	scanf("%d", &T);
	for (int i = 1; i <= T; i++)
	{
		printf("Case #%d: ", i);
		TC();
	}
	return 0;
}