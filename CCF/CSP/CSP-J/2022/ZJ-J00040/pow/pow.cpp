#include<bits/stdc++.h>
using namespace std;
long long a,b,t;
int flag=0;
long long cf(long long x,long long y) {
	if(flag)return 0;
	if(y==1)
		return x;
	if(y==0)
		return 1;
	if(y%2==0) {
		long long z=cf(x,y/2)*cf(x,y/2);
		if(z>10e9) {
			cout<<-1;
			flag=1;
		} else
			return z;
	}
	if(y%2==1) {
		long long z=cf(x,y/2)*cf(x,y/2)*x;
		if(z>1e9) {
			cout<<-1;
			flag=1;
		} else
			return z;
	}
}
int main() {
	freopen("pow.in","r",stdin);
	freopen("pow.out","w",stdout);
	cin>>a>>b;
	if(a==1) {
		cout<<1;
		return 0;
	}
	t=cf(a,b);
	if(!flag&&t<=1e9)cout<<t;
	else if(!flag)cout<<-1;
	return 0;
}