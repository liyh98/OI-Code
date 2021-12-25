#include <bits/stdc++.h>
using namespace std;

int main()
{
	char s[2][3];
	scanf("%s%s", s[0], s[1]);
	int c = 0;
	for (int i = 0; i < 2; i++)
		for (int j = 0; j < 2; j++)
			c += s[i][j] == '#';
	puts(c == 2 && ((s[0][0] == '#' && s[1][1] == '#') || (s[0][1] == '#' && s[1][0] == '#')) ? "No" : "Yes");
	return 0;
}