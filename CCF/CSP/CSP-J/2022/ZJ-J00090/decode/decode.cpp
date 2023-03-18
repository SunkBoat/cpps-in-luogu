#include <bits/stdc++.h>
using namespace std;
int t,f;
long long n,m,e,d,j,l,r,mid,k;
int main()
{
	freopen("decode.in","r",stdin);
	freopen("decode.out","w",stdout);
	cin>>t;
	while (t--)
	{
		f=0;
		cin>>n>>e>>d;//n=qi*pi
		m=n-e*d+2;//m=pi+qi
		if (m%2==1)
		{
		 l=m/2;
		 r=m/2+1;
		}
		else 
		{
			l=m/2-1;
			r=m/2+1;
		}
		mid=l;
		k=1;
		while (mid-k>1)
		{
			if (l*r>n) 
			{
				mid=l;
				l=(k+l)/2;
				r=m-l;
			}
			if (l*r<n)  
			{
				k=l;
				l=(mid-l+1)/2+k;
				r=m-l;
			}
			if (l*r==n) 
			{
				cout<<l<<' '<<r<<endl;
				f=1;
				break;
			}
		}
		if (f==0) cout<<"NO"<<endl;
		f=0;
	}
}
