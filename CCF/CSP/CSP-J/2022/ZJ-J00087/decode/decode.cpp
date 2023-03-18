#include<bits/stdc++.h>
using namespace std;
long long n,e,d,p,q,k;
void erfen()
{
	p=0;
	q=0;
	long long t=n+2-d*e;
	long long l=1,r=t/2;
	while(l<=r)
	{
		long long mid=(l+r)/2;
		long long res=mid*(t-mid);
		if(res<n)
			l=mid+1;
		else if(res==n)
		{
			p=mid;
			q=t-mid;	
			return;
		}
		else
			r=mid-1;
	}
	return;
}
int main()
{
	freopen("decode.in","r",stdin);
	freopen("decode.out","w",stdout);
	cin>>k;
	while(k--)
	{
		cin>>n>>d>>e;
		if(n+2-d*e<0) cout<<"NO"<<endl;
		erfen();
		if(p==0&&q==0) cout<<"NO"<<endl;
		else cout<<p<<' '<<q<<endl;
	}
	return 0;
}
