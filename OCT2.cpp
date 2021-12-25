#include <bits/stdc++.h>
using namespace std;

int a[200001];
int main() {
	int n;
	scanf("%d",&n);
	for (int i=1;i<=n;i++) scanf("%d",&a[i]);
	sort(a+1,a+n+1);
	int ans=0;
	for (int i=1;i<=n;i++) {
		if (ans<a[i]) ans++;
	}
	printf("%d",ans);
	return 0;
}
