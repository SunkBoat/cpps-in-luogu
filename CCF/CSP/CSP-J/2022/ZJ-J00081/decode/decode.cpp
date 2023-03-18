#include<bits/stdc++.h>
using namespace std;
inline long long read()
{
	register long long x=0,t=1;
	register char ch=getchar();
	while(ch<'0'||ch>'9')
	{
		if(ch=='-') t=-1;
		ch=getchar();
	}
	while(ch>='0'&&ch<='9')
	{
		x=(x<<1)+(x<<3)+(ch^48);
		ch=getchar();
	}
	return x*t;
}
inline void solve()
{
	register long long  n=read(),d=read(),e=read();
	register long long m=n-d*e+2;
	if(m<=1) 
	{
		puts("NO");
		return;
	}
	register long long l=1,r=m/2;
	while(l<=r)
	{
		register long long mid=(l+r)>>1;
		if(mid*(m-mid)>n) r=mid-1;
		if(mid*(m-mid)<n) l=mid+1;
		if(mid*(m-mid)==n)
		{
			l=mid;
			r=mid;
			break;
		}
	}
	if(l*(m-l)==n)
	{
		printf("%lld %lld\n",l,m-l);
		return ;
	}
	if(r*(m-r)==n)
	{
		printf("%lld %lld\n",r,m-r);
		return ;
	}
	puts("NO");
	return;
}
int main()
{
	freopen("decode.in","r",stdin);
	freopen("decode.out","w",stdout);
	long long k=read();
	for(register int i = 1;i<=k;i++) solve();
	return 0;
}