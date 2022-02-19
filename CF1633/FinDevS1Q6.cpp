#include <bits/stdc++.h>
using namespace std;

const long double r = 0.05, u = 1.1, d = 0.95, strike = 100, q = (exp(0.05L) - 0.95) / 0.15;
const int N = 20;

long double evaluate(bool isCall, double v)
{
    long double ret = isCall ? v - strike : strike - v;
    return ret < 0 ? 0 : ret;
}

long double dfs(bool isCall, int step, double v)
{
    if (step == N)
        return evaluate(isCall, v);
    long double next = (dfs(isCall, step + 1, v * u) * q + dfs(isCall, step + 1, v * d) * (1 - q)) * exp(-r);
    long double now = evaluate(isCall, v);
    return next > now ? next : now;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout << "Call Price: " << dfs(true, 0, 100) << '\n';
    cout << "Put Price: " << dfs(false, 0, 100) << '\n';
    return 0;
}
