#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const vector<int> questions{
    2,
    3,
    186'647,
    13'651'973,
    89'998'849};

const int N = 100'000'000;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    vector<int> primes;
    vector<bool> v(N);
    for (int i = 2; i < N; i++)
    {
        if (!v[i])
            primes.push_back(i);
        for (auto &j : primes)
        {
            if (i * j >= N)
                break;
            v[i * j] = true;
            if (i % j == 0)
                break;
        }
    }
    for (auto &question : questions)
    {
        cout << question << ": ";
        cout << lower_bound(primes.begin(), primes.end(), question) - primes.begin() + 1 << '\n';
    }
    return 0;
}
