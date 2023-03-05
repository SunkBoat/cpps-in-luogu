#include<bits/stdc++.h>
using namespace std;
struct node
{
	long long x,y;
}a[100005];
bool cmp(node x,node y)
{
	if(x.y!=y.y)
		return x.y<y.y;
	else
		return x.x<y.x;
}
int main()
{
	freopen("point.in","r",stdin);
	freopen("point.out","w",stdout);
	int n,k,i,z;
	scanf("%d%d",&n,&k);
	for(i=1;i<=n;i++)
		cin>>a[i].x>>a[i].y;
	sort(a+1,a+n+1,cmp);
	z=n;
	for(i=1;i<n;i++)
	{
		if(a[i].x>a[i+1].x)
			z--;
	}
	printf("%d",z+k);
	return 0;
}