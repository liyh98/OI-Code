#include <bits/stdc++.h>
using namespace std;

int a[100];

int main()
{
	int T;
	scanf("%d", &T);
	while (T--)
	{
		int n;
		bool flag = 1;
		scanf("%d", &n);
		for (int i = 1; i <= n; i++)
		{
			scanf("%d", &a[i]);
			flag &= a[i] == i;
		}
		int ans = 0;
		if (flag)
			ans = 0;
		else if (a[1] == 1 || a[n] == n)
			ans = 1;
		else if (a[1] == n && a[n] == 1)
			ans = 3;
		else
			ans = 2;
		printf("%d\n", ans);
	}
}