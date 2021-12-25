#include <bits/stdc++.h>
using namespace std;

int main()
{
	cin.tie(0);
	int Q;
	cin >> Q;
	while (Q--)
	{
		string s, t, ss = "", tt = "";
		cin >> s >> t;
		int n = s.length(), m = t.length(), lcm;
		ss = s;
		for (lcm = n; lcm % m != 0; lcm += n)
			ss = ss + s;
		for (; lcm; lcm -= m)
			tt = tt + t;
		//cout << tt;
		if (ss == tt)
			cout << tt << '\n';
		else
			puts("-1");
	}
	return 0;
}