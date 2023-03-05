//csp j/s ++rp;
//ccf qvan1 qian2 zu3 zhi1 
//€€£ ti2 gao1 zu3 tai4 gui4
#include<iostream>
using namespace std;
long long n,b,ans=1;
const long long maxn=1000000000;
long long mypow(long long n,long long b){
	if(n>maxn)return -1;
	if(b==1)return n;
	if(b%2==0){
		return mypow(n*n,b/2);
	}else{
		long long x=mypow(n,b-1);
		if(maxn/x<n)return -1;
		return n*mypow(n,b-1);
	}
}
int main(){
    freopen("pow.in","r",stdin);
    freopen("pow.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	cin>>n>>b;
	cout<<mypow(n,b);
    return 0;
}