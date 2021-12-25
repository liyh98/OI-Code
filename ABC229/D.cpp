#include <bits/stdc++.h>
using namespace std;

int cnt[200001];
int main()
{
	string s;
	int k;
	cin.tie(0);
	cin >> s >> k;
	int n = s.length(), ans = 0;
	for (int i = 1, j = 0; i <= n; i++)
	{
		cnt[i] = cnt[i - 1] + (s[i - 1] == '.');
		while (cnt[i] - cnt[j] > k)
			j++;
		ans = max(ans, i - j);
	}
	cout << ans;
	return 0;
}