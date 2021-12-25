#include <bits/stdc++.h>
using namespace std;

int l[100001], r[100001];
int main()
{
	int N, Q;
	scanf("%d%d", &N, &Q);
	while (Q--)
	{
		int op, x, y;
		scanf("%d%d", &op, &x);
		if (op == 1)
		{
			scanf("%d", &y);
			r[x] = y;
			l[y] = x;
		}
		else if (op == 2)
		{
			scanf("%d", &y);
			r[x] = l[y] = 0;
		}
		else
		{
			while (l[x] != 0)
				x = l[x];
			vector<int> ans;
			while (x != 0)
			{
				ans.push_back(x);
				x = r[x];
			}
			printf("%d ", ans.size());
			for (int x : ans)
				printf("%d ", x);
			putchar('\n');
		}
	}
	return 0;
}