#include <iostream>
using namespace std;

int main()
{
	int T;
	cin >> T;
	while (T--)
	{
		int a, b;
		cin >> a;
		b = 100 - a;
		for (int i = 2; i <= a; i++)
		{
			while (a % i == 0 && b % i == 0)
				a /= i, b /= i;
		}
		cout << a + b << '\n';
	}
	return 0;
}