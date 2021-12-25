#include <bits/stdc++.h>
using namespace std;

inline void TC()
{
	int n, k, ma = 0;
	long long ans = 0;
	cin >> n >> k;
	vector<int> pos, neg;
	for (int i = 1; i <= n; i++)
	{
		int x;
		cin >> x;
		if (x > 0)
			pos.push_back(x);
		if (x < 0)
			neg.push_back(-x);
		ma = max(ma, abs(x));
	}
	sort(pos.begin(), pos.end());
	sort(neg.begin(), neg.end());
	for (int i = pos.size() - 1; i >= 0; i -= k)
	{
		ans += pos[i] << 1;
	}
	for (int i = neg.size() - 1; i >= 0; i -= k)
	{
		ans += neg[i] << 1;
	}
	cout << ans - ma << '\n';
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