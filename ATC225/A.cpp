#include <bits/stdc++.h>
using namespace std;

int main()
{
	string s;
	cin >> s;
	int cnt = 0;
	for (int i = 0; i < 3; i++)
	{
		bool flag = 1;
		for (int j = 0; j < i; j++)
			if (s[j] == s[i])
				flag = 0;
		cnt += flag;
	}
	if (cnt == 1)
		puts("1");
	else if (cnt == 2)
		puts("3");
	else
		puts("6");
	return 0;
}