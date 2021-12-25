#include <cstdio>
#include <queue>
using namespace std;

int main()
{
	deque<int> q;
	int n;
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
	{
		int x;
		scanf("%d", &x);
		if (i & 1)
			q.push_back(x);
		else
			q.push_front(x);
	}
	if (n & 1)
	{
		for (int i = 0; i < n; i++)
		{
			printf("%d ", q.back());
			q.pop_back();
		}
	}
	else
	{
		for (int i = 0; i < n; i++)
		{
			printf("%d ", q.front());
			q.pop_front();
		}
	}
	return 0;
}