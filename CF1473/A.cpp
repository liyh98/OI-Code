#include <bits/stdc++.h>
using namespace std;

int main()
{
	int T;
	scanf("%d", &T);
	while (T--)
	{
		int n, d, mi1 = 100, mi2 = 100;
		bool flag = 1;
		scanf("%d%d", &n, &d);
		while (n--)
		{
			int x;
			scanf("%d", &x);
			if (x > d)
				flag = 0;
			if (mi1 > x)
				mi2 = mi1, mi1 = x;
			else if (mi2 > x)
				mi2 = x;
		}
		puts(flag | (mi1 + mi2 <= d) ? "YES" : "NO");
	}
	return 0;
}