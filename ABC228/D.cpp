#include <bits/stdc++.h>
using namespace std;

const int N = 1 << 20;
set<int> s;
long long a[N];

int main()
{
	cin.tie(0);
	for (int i = 0; i < N; i++)
		s.insert(i), a[i] = -1;
	int q;
	cin >> q;
	while (q--)
	{
		int t;
		long long x;
		cin >> t >> x;
		if (t == 1)
		{
			auto it = s.lower_bound(x % N);
			if (it == s.end())
				it = s.begin();
			a[*it] = x;
			s.erase(it);
		}
		else
			cout << a[x % N] << '\n';
	}
}