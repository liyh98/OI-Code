#include <bits/stdc++.h>
using namespace std;

int p[100001], h[100001];

int main()
{
	cin.tie(0);
	int n, k;
	cin >> n >> k;
	for (int i = 1; i <= n; i++)
	{
		int x;
		for (int j = 0; j < 3; j++)
		{
			cin >> x;
			p[i] += x;
		}
		h[i] = p[i];
	}
	sort(h + 1, h + n + 1);
	int target = h[n + 1 - k];
	for (int i = 1; i <= n; i++)
		puts(p[i] + 300 >= target ? "Yes" : "No");
	return 0;
}