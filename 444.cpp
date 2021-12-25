#include <cstdio>
#include <utility>
#include <algorithm>
#include <set>
using namespace std;

int a[200001], cnt;
pair<int, int> b[200001];
int main()
{
	int n, pre = -1;
	scanf("%d", &n);
	for (int i = 1; i <= n; i++)
	{
		int x;
		scanf("%d", &x);
		if (x != pre)
		{
			a[++cnt] = x;
			b[cnt] = make_pair(a[cnt], cnt);
		}
		pre = x;
	}
	sort(b + 1, b + cnt + 1);
	int ans = 0;
	b[0].first = -1;
	set<int> s;
	for (int i = 1; i <= cnt; i++)
	{
		if (b[i].first == 0)
			continue;
		s.insert(b[i].second);
		if (b[i].first != b[i - 1].first)
			ans++;
	}
	printf("%d\n", ans);
	int tot = cnt;
	for (int i = 1; i <= cnt; i++)
	{
		if (b[i].first == 0)
			continue;
		int j = i;
		while (b[j + 1].first == b[i].first)
			j++;
		for (int k = i; k <= j; k++)
		{
			int x = b[k].second;
			s.erase(x);
			set<int>::iterator it = s.lower_bound(x);
			if (x != cnt && (it == s.end() || *it > x + 1))
				tot--;
			if (x != 1 && (it == s.begin() || *(--it) < x - 1))
				tot--;
		}
		printf("%d ", tot);
		i = j;
	}
	return 0;
}