#include <bits/stdc++.h>
using namespace std;

bool compare(string s, string t)
{
	if (s + t != t + s)
		return s + t < t + s;
	return s < t;
}

string S[51];
int main()
{
	int N, K;
	cin.tie(0);
	cin >> N >> K;
	for (int i = 1; i <= N; i++)
		cin >> S[i];
	sort(S + 1, S + N + 1, compare);
	for (int i = 1; i < K; i++)
		cout << S[i];
	string last = S[K];
	for (int i = K + 1; i <= N; i++)
		if (S[i] < last)
			last = S[i];
	cout << last;
	return 0;
}