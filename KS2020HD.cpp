#include <bits/stdc++.h>
using namespace std;

int dis[26][26];
char S[500001][21];
inline void TC()
{
	int N, Q;
	scanf("%d%d", &N, &Q);
	for (int i = 0; i < 26; i++)
		for (int j = i + 1; j < 26; j++)
			dis[i][j] = dis[j][i] = N + 1;
	for (int i = 1; i <= N; i++)
	{
		scanf("%s", S[i]);
		int l = strlen(S[i]);
		for (int j = 0; j < l; j++)
			for (int k = j + 1; k < l; k++)
				if (S[i][j] != S[i][k])
				{
					int a = S[i][j] - 'A', b = S[i][k] - 'A';
					dis[a][b] = dis[b][a] = 1;
				}
	}
	for (int k = 0; k < 26; k++)
		for (int i = 0; i < 26; i++)
			if (i != k)
				for (int j = 0; j < 26; j++)
					if (k != j && i != j)
						dis[i][j] = min(dis[i][j], dis[i][k] + dis[k][j]);
	while (Q--)
	{
		int X, Y;
		scanf("%d%d", &X, &Y);
		int lenX = strlen(S[X]), lenY = strlen(S[Y]), ans = N + 1;
		for (int i = 0; i < lenX; i++)
			for (int j = 0; j < lenY; j++)
				ans = min(ans, dis[S[X][i] - 'A'][S[Y][j] - 'A']);
		printf("%d ", ans == N + 1 ? -1 : ans + 2);
	}
	putchar('\n');
}

int main()
{
	int T;
	scanf("%d", &T);
	for (int i = 1; i <= T; i++)
	{
		printf("Case #%d: ", i);
		TC();
	}
	return 0;
}