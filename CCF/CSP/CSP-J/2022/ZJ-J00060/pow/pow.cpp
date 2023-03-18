#include<bits/stdc++.h>
using namespace std;
long long a,b;
long long get(long long a,long long b){
	long long res=1;
	long long base=a,k=b;
	while(k){
		if(base>1e9)return -1;
		if(k%2==1){
			res*=base;
			k--;
		}
		k/=2;
		base=base*base;
		if(res>1e9)return -1;
	}
	return res;
}
int main(){
	freopen("pow.in","r",stdin);
	freopen("pow.out","w",stdout);
	cin>>a>>b;
	cout<<get(a,b);
	
	return 0;
}