#include <bits/stdc++.h>
using namespace std;

int main()
{
	int N, M;
	scanf("%d%d", &N, &M);
	int f;
	scanf("%d", &f);
	if ((f - 1) % 7 + 1 + M - 1 > 7)
	{
		puts("No");
		return 0;
	}
	for (int i = 1; i <= N; i++)
		for (int j = 1; j <= M; j++)
		{
			int x = f;
			if (i > 1 || j > 1)
				scanf("%d", &x);
			if (x != f + (i - 1) * 7 + j - 1)
			{
				puts("No");
				return 0;
			}
		}
	puts("Yes");
	return 0;
}