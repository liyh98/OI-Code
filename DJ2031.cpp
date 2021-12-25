#include <bits/stdc++.h>
using namespace std;

priority_queue<pair<int, long long>, vector<pair<int, long long>>, greater<pair<int, long long>>> pq;

int main()
{
	int n;
	cin.tie(0);
	cin >> n;
	for (int i = 1; i <= n; i++)
	{
		int l, c;
		cin >> l >> c;
		pq.emplace(l, c);
	}
	long long ans = 0;
	while (pq.size() > 1)
	{
		int l1, l2;
		long long c1, c2;
		tie(l1, c1) = pq.top();
		pq.pop();
		tie(l2, c2) = pq.top();
		if (l1 == l2)
		{
			pq.pop();
			ans += c1 + c2;
			pq.emplace(l1 + 1, c1 + c2);
		}
	}
	cout << ans;
	return 0;
}