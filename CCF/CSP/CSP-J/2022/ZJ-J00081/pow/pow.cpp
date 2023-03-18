#include<bits/stdc++.h>
using namespace std;
const long long mod=1e9; 
long long a,b;
inline long long qsm(long long shu,long long mi)
{
	long long x=1,k=shu;
	while(mi)
	{
		if(x>mod) return -1;
		if(mi&1)
		{
			x*=k;
		}
		mi/=2;
		k=k*k;
		if(x>mod) return -1;
	}
	return x;
} 
int main()
{
	freopen("pow.in","r",stdin);
	freopen("pow.out","w",stdout);
	cin >> a >> b;
	cout<<qsm(a,b);
	return 0;
}