#include <bits/stdc++.h>
using namespace std;

int a[300001];
bool b[300001];

inline void TC()
{
	int n;
	scanf("%d", &n);
	for (int i = 1; i <= n; i++)
		scanf("%d", &a[i]);
	int ans = 0, consec = 0, ma = 0;
	for (int i = 2; i < n; i++)
	{
		b[i] = ((a[i] > a[i - 1]) & (a[i] > a[i + 1])) | ((a[i] < a[i - 1]) & (a[i] < a[i + 1]));
		if (b[i])
		{
			ans++, consec++;
			if (consec != 2)
				ma = max(ma, consec);
			else if (a[i] > a[i - 1] && (i == 3 || i == n - 1 || a[i - 2] == a[i - 3] || a[i + 1] == a[i + 2] || a[i] <= a[i - 2] || a[i - 1] >= a[i + 1]))
				ma = max(ma, 2);
			else if (a[i] < a[i - 1] && (i == 3 || i == n - 1 || a[i - 2] == a[i - 3] || a[i + 1] == a[i + 2] || a[i] >= a[i - 2] || a[i - 1] <= a[i + 1]))
				ma = max(ma, 2);
		}
		else
			consec = 0;
	}
	ans -= min(ma, 3);
	printf("%d\n", ans);
}

int main()
{
	int T;
	scanf("%d", &T);
	while (T--)
		TC();
	return 0;
}