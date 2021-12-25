#include <bits/stdc++.h>
using namespace std;

#define MOD 998244353
int a[100001];
inline void TC()
{
	int n;
	scanf("%d", &n);
	for (int i = 1; i <= n; i++)
		scanf("%d", &a[i]);
	pair<int, int> cnt[2][n];
	int len[] = {0, 0};
	long long ans = 0;
	for (int i = n, o = 0; i; i--, o ^= 1)
	{
		//printf("%d\n", i);
		for (int j = 0; j < len[o]; j++)
		{
			auto p = cnt[o][j];
			int c = (a[i] - 1) / p.first;
			int slice = a[i] / (c + 1);
			if (len[!o] && cnt[!o][len[!o] - 1].first == slice)
				cnt[!o][len[!o] - 1].second += p.second;
			else
				cnt[!o][len[!o]++] = make_pair(slice, p.second);
			if (c)
				ans += 1LL * c * p.second * i;
			//printf("%d ", c * it->second * i);
		}
		ans %= MOD;
		if (len[!o] && cnt[!o][len[!o] - 1].first == a[i])
			cnt[!o][len[!o] - 1].second += 1;
		else
			cnt[!o][len[!o]++] = make_pair(a[i], 1);
		len[o] = 0;
	}
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