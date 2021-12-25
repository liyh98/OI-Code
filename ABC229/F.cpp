#include <bits/stdc++.h>
using namespace std;

int a[200001], b[200001];
long long f[200001][2][2];
int main()
{
	int n;
	cin.tie(0);
	cin >> n;
	for (int i = 1; i <= n; i++)
		cin >> a[i];
	for (int i = 1; i <= n; i++)
		cin >> b[i];
	f[1][0][0] = a[1];
	f[1][1][1] = 0;
	f[1][0][1] = f[1][1][0] = 200000000000000ll;
	for (int i = 2; i <= n; i++)
	{
		for (int o = 0; o < 2; o++)
		{
			f[i][o][0] = min(f[i - 1][o][0] + a[i] + b[i - 1], f[i - 1][o][1] + a[i]);
			f[i][o][1] = min(f[i - 1][o][0], f[i - 1][o][1] + b[i - 1]);
		}
	}
	long long ans = LLONG_MAX;
	for (int i = 0; i < 2; i++)
		for (int j = 0; j < 2; j++)
			ans = min(ans, f[n][i][j] + (i == j ? b[n] : 0));
	cout << ans;
	return 0;
}