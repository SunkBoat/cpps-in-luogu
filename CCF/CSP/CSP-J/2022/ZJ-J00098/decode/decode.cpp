#include<bits/stdc++.h>
using namespace std;
long long k,n,d,e,p,q,m;
bool f;
int main()
{
	freopen("decode.in","r",stdin);
	freopen("decode.out","w",stdout);
	cin>>k;
	for(int i=1;i<=k;++i)
	{
		cin>>n>>d>>e;
		m=d*e-1;
		f=false;
		for(int j=2;j<=sqrt(n);j++)
		{
			if(n%j==0)
			{
				p=j;
				q=n/j;
				if((p-1)*(q-1)+1==e*d)
				{
					cout<<p<<" "<<q<<endl;
					f=!f;
					break;
				}
			}
		}
		if(!f) cout<<"NO"<<endl;
	}
	return 0;
}
//
/*
p     q
p-1 q-1

2*3=6;
1*2=2;

2*4=8;
1*3=3;


3*4=12;
2*3=6;

5*7=35;
4*6=24;

p*q-(p-1)*(q-1)+1
*/
