#include <bits/stdc++.h>
using namespace std;

pair<int, int> a[300001];
int main()
{
	int n, w;
	cin.tie(0);
	cin >> n >> w;
	for (int i = 1; i <= n; i++)
		cin >> a[i].first >> a[i].second;
	sort(a + 1, a + n + 1);
	long long ans = 0;
	for (int i = n; i && w; i--)
	{
		int used = min(w, a[i].second);
		ans += (long long)a[i].first * used;
		w -= used;
	}
	cout << ans;
	return 0;
}