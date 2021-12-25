#include <bits/stdc++.h>
using namespace std;

int get(int x) {
	if (!x) return 0;
	int ret = get(x - 1);
	if (!(x & 1)) ret = min(ret, get(x >> 1));
	if (x % 3 == 0) ret = min(ret, get(x / 3));
	return ret + 1;
}


int main() {
	clock_t starttime, endtime;
    int n;
    scanf("%d", &n);
    starttime = clock();
    while (n--) {
        int x;
        scanf("%d", &x);
        printf("%d\n", get(x));
    }
    endtime = clock();
    printf("%.3lf", (double)(endtime-starttime)/CLOCKS_PER_SEC);
    return 0;
}
