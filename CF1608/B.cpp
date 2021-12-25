#include <bits/stdc++.h>
using namespace std;

short ind[100001];
int ans[100001];
bool sign[100001];
inline void TC()
{
	int n, a, b;
	scanf("%d%d%d", &n, &a, &b);
	memset(ind, 0, sizeof ind);
	if (abs(a - b) <= 1 && a + b <= n - 2)
	{
		if (a >= b)
			ind[1]++, sign[1] = 0;
		else
			ind[2]++, sign[1] = 1;
		int i, o;
		for (i = 2, o = b > a; i < n && (a || b); i++, o ^= 1)
		{
			if (!o)
			{
				ind[i + 1]++;
				sign[i] = 1;
				a--;
			}
			else
			{
				ind[i]++;
				sign[i] = 0;
				b--;
			}
		}
		for (; i < n; i++)
			sign[i] = sign[i - 1], ind[i + sign[i]]++;
		queue<int> q;
		for (int i = 1; i <= n; i++)
		{
			if (!ind[i])
				q.push(i);
		}
		int t = n;
		while (!q.empty())
		{
			int x = q.front();
			q.pop();
			ans[x] = t--;
			if (x > 1 && !sign[x - 1])
			{
				if (!(--ind[x - 1]))
					q.push(x - 1);
			}
			if (x < n && sign[x])
			{
				if (!(--ind[x + 1]))
					q.push(x + 1);
			}
		}
		for (int i = 1; i <= n; i++)
			printf("%d ", ans[i]);
		putchar('\n');
	}
	else
	{
		puts("-1");
		return;
	}
}

int main()
{
	int T;
	scanf("%d", &T);
	while (T--)
		TC();
	return 0;
}