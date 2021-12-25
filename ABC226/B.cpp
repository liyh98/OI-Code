#include <bits/stdc++.h>
using namespace std;

string a[200001];

int main()
{
	int N;
	cin.tie(0);
	cin >> N;
	for (int i = 1; i <= N; i++)
	{
		int L;
		cin >> L;
		string t;
		for (int i = 1; i <= L; i++)
		{
			int x;
			cin >> x;
			t += to_string(x) + ' ';
		}
		a[i] = t;
	}
	sort(a + 1, a + N + 1);
	cout << unique(a + 1, a + N + 1) - a - 1;
	return 0;
}