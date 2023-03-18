#include<iostream>
using namespace std;
long long int ksm(int a,int b){
	long long int res=1;
	while(b){
		if(b&1) res*=a;
		a=a*a;
		b>>=1;
		if(res>1000000000ll||res==0) return -1;
	}
	return res;
}
int main(){
	freopen("pow.in","r",stdin);
	freopen("pow.out","w",stdout);
	int a,b;
	cin>>a>>b;
	cout<<ksm(a,b);
	return 0;
}