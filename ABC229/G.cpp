#include <bits/stdc++.h>
using namespace std;

char s[200002];
int cnt[200001], y[200001];

int main()
{
	long long k;
	scanf("%s%lld", s + 1, &k);
	int n = strlen(s + 1), m = 0;
	for (int i = 1; i <= n; i++)
	{
		cnt[i] = cnt[i - 1] + (s[i] == '.');
		if (s[i] == 'Y')
			y[++m] = i;
	}
	int ans = 0;
	for (int i = 1, l = 1, r = 1; i <= m; i++)
	{
		if (i > 1)
			k += (long long)(cnt[y[i]] - cnt[y[i - 1]]) * (r >= i ? r - i - i + l + 1 : -i + l);
		r = max(r, i);
		while (l < i && k < 0)
			k += cnt[y[i]] - cnt[y[l++]];
		while (r < m && l < i && cnt[y[r + 1]] - cnt[y[i]] < cnt[y[i]] - cnt[y[l]])
		{
			k += (cnt[y[i]] - cnt[y[l]]) - (cnt[y[r + 1]] - cnt[y[i]]);
			l++, r++;
		}
		while ((r < m && k >= cnt[y[r + 1]] - cnt[y[i]]) || (l > 1 && k >= cnt[y[i]] - cnt[y[l - 1]]))
		{
			if (!(l > 1 && k >= cnt[y[i]] - cnt[y[l - 1]]) || (r < m && k >= cnt[y[r + 1]] - cnt[y[i]] && cnt[y[r + 1]] - cnt[y[i]] < cnt[y[i]] - cnt[y[l - 1]]))
				k -= cnt[y[++r]] - cnt[y[i]];
			else
				k -= cnt[y[i]] - cnt[y[--l]];
		}
		ans = max(ans, r - l + 1);
	}
	cout << ans;
	return 0;
}