#include <bits/stdc++.h>
using namespace std;

int x[300001];
char d[300001][2];
void TC()
{
	int n, m;
	scanf("%d%d", &n, &m);
	for (int i = 1; i <= n; i++)
		scanf("%d", &x[i]);
	for (int i = 1; i <= n; i++)
		scanf("%s", d[i]);
}

int main()
{
	int T;
	scanf("%d", &T);
	while (T--)
	{
		TC();
	}
}