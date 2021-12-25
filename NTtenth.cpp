#include <cstdio>
using namespace std;

int r[] = {0, 1, 8, -7};
bool v[56];

void dfs(int l, int s)
{
	if (!l)
	{
		v[s] = 1;
		return;
	}
	for (int i = 0; i < 4; i++)
		dfs(l - 1, (s + r[i] + 56) % 56);
}

int main()
{
	for (int i = 1; i < 43; i++)
	{
		int r = 1;
		for (int j = 0; j < 7; j++)
			r = (r * i) % 43;
		printf("%d %d\n", i, r);
	}
	/*dfs(8, 0);
	for (int i = 0; i < 56; i++)
		if (!v[i])
			printf("%d\n", i);*/
	return 0;
}