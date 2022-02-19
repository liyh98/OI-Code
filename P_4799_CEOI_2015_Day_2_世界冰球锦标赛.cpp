/*
 * @Author: Yuhao.Li
 * @Date: 2022-02-19 22:38:32
 * @Last Modified by: Yuhao.Li
 * @Last Modified time: 2022-02-19 22:39:29
 */
#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    long long m;
    cin >> n >> m;
    int half = n >> 1;
    vector<long long> a(n);
    for (long long &x : a)
        cin >> x;
    vector<long long> price;
    price.reserve(1 << half);
    for (int i = 0; i < (1 << half); i++)
    {
        long long s = 0;
        for (int j = 0; j < half; j++)
            if ((i >> j) & 1)
                s += a[j];
        price.push_back(s);
    }
    sort(price.begin(), price.end());
    long long ans = 0;
    for (int i = 0; i < (1 << (n - half)); i++)
    {
        long long s = 0;
        for (int j = 0; j < n - half; j++)
            if ((i >> j) & 1)
                s += a[j + half];
        ans += upper_bound(price.begin(), price.end(), m - s) - price.begin();
    }
    cout << ans;
    return 0;
}
