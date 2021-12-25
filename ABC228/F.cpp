#include <bits/stdc++.h>
using namespace std;

long long s[1001][1001], b[1001][1001];
multiset<long long> cs[1001];

int main()
{
	cin.tie(0);
	int h, w, x, h1, h2, w1, w2;
	cin >> h >> w >> h1 >> w1 >> h2 >> w2;
	for (int i = 1; i <= h; i++)
		for (int j = 1; j <= w; j++)
		{
			cin >> x;
			s[i][j] = s[i][j - 1] + s[i - 1][j] - s[i - 1][j - 1] + x;
		}
	int hh = min(h1, h2), ww = min(w1, w2);
	for (int i = 0; i <= h - hh; i++)
		for (int j = 0; j <= w - ww; j++)
		{
			b[i][j] = s[i + hh][j + ww] - s[i][j + ww] - s[i + hh][j] + s[i][j];
		}
	int hb = max(1, h1 - h2 + 1), wb = max(1, w1 - w2 + 1);
	long long ans = 0;
	for (int j = 0; j < w; j++)
	{
		for (int i = 0; i < hb; i++)
			cs[j].insert(b[i][j]);
	}
	for (int i = 0; i <= h - h1; i++)
	{
		if (i)
			for (int k = 0; k < w; k++)
			{
				cs[k].erase(cs[k].find(b[i - 1][k]));
				cs[k].insert(b[i + hb - 1][k]);
			}
		multiset<long long> rs;
		for (int j = 0; j <= w - w1; j++)
		{
			if (!j)
			{
				//cout << "L39";
				for (int k = 0; k < wb; k++)
				{
					auto it = cs[k].end();
					rs.insert(*(--it));
				}
			}
			else
			{
				//cout << "L52";
				auto it = cs[j - 1].end();
				rs.erase(rs.find(*(--it)));
				it = cs[j + wb - 1].end();
				rs.insert(*(--it));
			}
			auto it = rs.end();
			ans = max(ans, s[i + h1][j + w1] - s[i][j + w1] - s[i + h1][j] + s[i][j] - *(--it));
		}
	}
	cout << ans;
	return 0;
}