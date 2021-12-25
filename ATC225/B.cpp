#include <bits/stdc++.h>
using namespace std;

int d[100001];
int main()
{
	int N;
	scanf("%d", &N);
	bool ans = 0;
	for (int i = 1; i < N; i++)
	{
		int x, y;
		scanf("%d%d", &x, &y);
		d[x]++, d[y]++;
		if (d[x] == N - 1 || d[y] == N - 1)
			ans = 1;
	}
	puts(ans ? "Yes" : "No");
	return 0;
}