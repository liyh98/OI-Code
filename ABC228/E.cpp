#include <bits/stdc++.h>
using namespace std;

#define MOD 998244353

long long fastExpo(long long base, long long expo, int mod = MOD)
{
	long long ret = 1;
	for (base %= mod; expo; expo >>= 1, (base *= base) %= mod)
		if (expo & 1)
			(ret *= base) %= mod;
	return ret;
}

int main()
{
	long long n, k, m;
	cin >> n >> k >> m;
	if (m % MOD == 0)
		cout << 0;
	else
		cout << fastExpo(m, fastExpo(k, n, MOD - 1));
}