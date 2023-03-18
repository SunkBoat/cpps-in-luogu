#include<bits/stdc++.h>
using namespace std;
long long TIAOSHI=0;
void pd()
{
	long long n,e,d;
	cin>>n>>e>>d;
	long long jia=n+2-e*d;
	if (TIAOSHI) cout<<"a+b="<<jia<<"\n";
	long long chen=n;
	long long a=jia,b=chen;


	double data=1.0*(a*a-4*b);
	if (TIAOSHI) cout<<"data="<<data<<"\n";
	double t=sqrt(data);
	{
		long long q=t;
		if (t-1.0*q>0.000001)
		{
			cout<<"NO\n";
			return;

		}
		if (data<0)
		{
			cout<<"NO\n";
			return;
		}
	}
	if (TIAOSHI) cout<<"sqrt(data)="<<sqrt(data)<<"\n";

	double x=(a-t)/2;
	double y=(a+t)/2;
	{
		long long q=x;
		if (x-1.0*q>0.000001)
		{
			cout<<"NO\n";
			return;

		}
	}
	if (x<0)
	{
		cout<<"NO\n";
		return;
	}
	{
		int x=(a-t)/2;
		int y=(a+t)/2;
		cout<<x<<' '<<y<<"\n";
	}
}
int main()
{
	freopen("decode.in","r",stdin);freopen("decode.out","w",stdout);
	int m;
	cin>>m;
	for (int i=0; i<m; i++)
	{
		pd();
	}
	return 0;
}

