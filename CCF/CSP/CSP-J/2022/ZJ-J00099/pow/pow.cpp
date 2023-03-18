#include<bits/stdc++.h>
using namespace std;
long long _pow(long long a,long long b){
	long long res=1;
	while(b){
		if(res>1e9||a>1e9) return -1;
		if(b%2==0){
			b/=2;
			a=a*a;
		}
		else {
			b-=1;
			res*=a;
			b/=2;
			a=a*a;
		}
	}
	return res;
}
int main(){
	freopen("pow.in","r",stdin);
	freopen("pow.out","w",stdout);
	long long a,b;
	cin>>a>>b;
	cout<<_pow(a,b);
	return 0;
}