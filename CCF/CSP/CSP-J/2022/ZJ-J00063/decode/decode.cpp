#include<bits/stdc++.h>
using namespace std;
long long read()
{
	long long x=0,f=1;
	char ch=getchar();
	while(ch>'9' || ch<'0')
	{
		if(ch=='-') f=-1;
		ch=getchar();
	}
	while(ch>='0' && ch<='9')
	{
		x=x*10+(ch-'0');
		ch=getchar();
	}
	return x*f;
}
int k;
long long n,e,d,a,b;
long long mm,m;
int main()
{
	freopen("decode.in","r",stdin);
	freopen("decode.out","w",stdout);
	cin>>k;
	while(k)
	{
		n=read(),d=read(),e=read();
		m=n-e*d+2;
		mm=m*m-4*n;
		if(sqrt(mm)*sqrt(mm)!=mm)
		{
			cout<<"NO"<<endl;
		}
		else 
		{
			mm=sqrt(mm);
			long long mm1=m+mm;
			long long mm2=m-mm;
			bool f1=true,f2=true;
			if(mm1%2==1 || mm1<0) f1=false; 
			if(mm2%2==1 || mm2<0) f2=false;
			if(f1==false && f2==false) cout<<"NO"<<endl;
			else if(f1==true) a=mm1/2;
			else if(f2==true) a=mm2/2;
			if(f1==true || f2==true)
			{
				b=m-a;
				if(b<a) swap(a,b);
				cout<<a<<" "<<b<<endl;
			}
		}
		k--;
	}
	return 0;
}
