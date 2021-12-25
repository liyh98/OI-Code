#include <cstdio>
#include <cstring>
using namespace std;

int l[100001], r[100001];

void insert(int &x, int key)
{
	if (x == 0)
	{
		x = key;
		return;
	}
	if (key < x)
		insert(l[x], key);
	else
		insert(r[x], key);
}

int level = 1, k;
int ans = 0;
void dfs(int x)
{
	if (level == k)
		ans++;
	if (l[x] != 0)
		dfs(l[x]);
	if (r[x] != 0)
	{
		level++;
		dfs(r[x]);
	}
}

int main()
{
	int n;
	scanf("%d%d", &n, &k);
	int root = 0;
	for (int i = 1; i <= n; i++)
	{
		int x;
		scanf("%d", &x);
		insert(root, x);
	}
	dfs(root);
	printf("%d", ans);
	return 0;
}