#include <bits/stdc++.h>
using namespace std;

int main()
{
	long long a, b;
	cin >> a >> b;
	while (a && b)
	{
		if ((a % 10) + (b % 10) >= 10)
		{
			puts("Hard");
			return 0;
		}
		a /= 10, b /= 10;
	}
	puts("Easy");
	return 0;
}