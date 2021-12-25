#include <bits/stdc++.h>
using namespace std;

int main() {
    int c=0;
    for (int i = 0; i <(1 <<10); i++)
    if (!(i&(i<<1))&&!(i&(i<<2))) c++;
    cout << c;
    return 0;
}