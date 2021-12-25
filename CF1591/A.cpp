#include <bits/stdc++.h>
using namespace std;

inline void TC()
{
	int n, pre = 2, x = 0, now = 1;
	cin >> n;
	for (int i = 1; i <= n; i++)
	{
		cin >> x;
		if (now == -1)
			continue;
		if (x)
			now += pre == 1 ? 5 : 1;
		else if (!pre)
			now = -1;
		pre = x;
	}
	cout << now << '\n';
}
int main()
{
	int t;
	cin.tie(0);
	cin >> t;
	while (t--)
		TC();
	return 0;
}