#include <algorithm>
#include <climits>
#include <cstdio>
using namespace std;

int a[2000001],b[2000001],ca,cb,p[4000001];
long long sa,sb,base;
int main()
{
	int r,n;
	scanf("%d%d",&r,&n);
	cb=r;
	for (int i=1;i<=r;i++)
	{
		int x,y;
		scanf("%d%d",&x,&y);
		a[i]=min(x,y);
		b[i]=max(x,y);
		sb+=a[i];
		p[i*2-1]=x;
		p[i*2]=y;
		base+=b[i]-a[i];
	}
	sort(a+1,a+r+1);
	sort(b+1,b+r+1);
	sort(p+1,p+r+r+1);
	int j=1,k=1,pans=0;
	long long ans=LLONG_MAX;
	for (int i=1;i<=(r<<1);i++)
	{
		while (b[j]<p[i])
		{
			sa+=b[j];
			ca++;
			j++;
		}
		while (k<=r&&a[k]<=p[i])
		{
			sb-=a[k];
			cb--;
			k++;
		}
		long long t=(long long)ca*p[i]-sa;
		t+=sb-(long long)cb*p[i];
		if (ans>t)
		{
			ans=t;
			pans=p[i];
		}
	}
	printf("%d %lld",pans, ans*2+base);
	return 0;
}
