#include <bits/stdc++.h>
using namespace std;

int main()
{
	int s, t, x;
	cin >> s >> t >> x;
	if (s <= t)
		cout << (s <= x && x < t ? "Yes" : "No");
	else
		cout << (s <= x || x < t ? "Yes" : "No");
	return 0;
}