#include <bits/stdc++.h>
using namespace std;

inline void TC()
{
	int n;
	cin >> n;
	stack<int> st;
	for (int i = 1; i <= n; i++)
	{
		int x;
		cin >> x;
		while (!st.empty() && st.top() <= x)
			st.pop();
		st.push(x);
	}
	cout << st.size() - 1 << '\n';
}
int main()
{
	int t;
	cin.tie(0);
	cin >> t;
	while (t--)
		TC();
	return 0;
}