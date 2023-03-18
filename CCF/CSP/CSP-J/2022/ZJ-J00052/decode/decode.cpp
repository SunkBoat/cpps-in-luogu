#include<iostream>
using namespace std;
int t,cnt;
bool flag;
long long n,x,y,sum;
void search(long long x,long long y,long long maxx)
{
	if(x+y==sum)
	{
		if(x>y) swap(x,y);
		printf("%lld %lld\n",x,y);
		flag=1;
		return ;
	}
	if(x+y<sum||x>y||flag) return ;
	for(int j=maxx;j<=y;j++)
	{
		if(y%j==0) search(x*j,y/j,j);
		if(flag) return ;
	}
}
int main()
{
	freopen("decode.in","r",stdin);
	freopen("decode.out","w",stdout);
	scanf("%d",&t);
	while(t--)
	{
		scanf("%lld%lld%lld",&n,&x,&y);
		sum=-(x*y-n-2);
		flag=0;
		for(int i=2;i<=n;i++)
		{
			if(n%i==0) search(i,n/i,i);
			if(flag) break;
		}
		if(!flag) printf("NO\n");
	}
	return 0;
}
