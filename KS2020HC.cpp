#include <bits/stdc++.h>
using namespace std;

int X[100001], Y[100001];
inline void TC()
{
	int N;
	scanf("%d", &N);
	for (int i = 1; i <= N; i++)
		scanf("%d%d", &X[i], &Y[i]);
	sort(X + 1, X + N + 1);
	sort(Y + 1, Y + N + 1);
	for (int i = 1; i <= N; i++)
		X[i] -= i;
	sort(X + 1, X + N + 1);
	long long ans = 0, minX = LLONG_MAX;
	int targetX = X[(N + 1) >> 1], targetY = Y[(N + 1) >> 1];
	for (int i = 1; i <= N; i++)
		ans += (long long)abs(targetX - X[i]) + abs(targetY - Y[i]);
	printf("%lld\n", ans);
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