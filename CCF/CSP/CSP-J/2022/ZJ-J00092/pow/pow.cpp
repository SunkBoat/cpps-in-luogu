#include<bits/stdc++.h>
using namespace std;
const long long NN=1e9;
long long a,b;
long long p(long long x,long long y)
{
	long long sum=1;
	for (;y;x=x*x,y>>=1)
	{
		if (x>NN) return -1;
		if (y&1) sum*=x;
		if (sum>NN) return -1;
	}
	return sum;
}
int main()
{
	freopen("pow.in","r",stdin);
	freopen("pow.out","w",stdout);
	cin>>a>>b;
	cout<<p(a,b)<<endl;
	return 0;
 } 
