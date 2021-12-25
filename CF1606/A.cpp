#include <bits/stdc++.h>
using namespace std;

char s[105];
int main()
{
	int T;
	scanf("%d", &T);
	while (T--)
	{
		scanf("%s", s + 1);
		int n = strlen(s + 1);
		s[n] = s[1];
		printf("%s\n", s + 1);
	}
	return 0;
}