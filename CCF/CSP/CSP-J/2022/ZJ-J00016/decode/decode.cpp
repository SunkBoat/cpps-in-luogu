#include<bits/stdc++.h>
using namespace std;
int k;
long long n,e,d;
int main()
{
	freopen("decode.in","r",stdin);
	freopen("decode.out","w",stdout);
	cin>>k;
	while(k--)
	{
		cin>>n>>e>>d;
		bool b=0;
		long long p,q;
		for(p=1;p<=n/p;++p)
		{
			if(n%p==0)
			{
				q=n/p;
				if(e*d==(p-1)*(q-1)+1)
				{
					b=1;
					cout<<p<<' '<<q<<endl;
					break;
				}
			}
		}
		if(!b) cout<<"NO"<<endl;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}

