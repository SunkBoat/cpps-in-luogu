//csp j/s ++rp;
//ccf qvan1 qian2 zu3 zhi1 
//€€£ ti2 gao1 zu3 tai4 gui4
#include<iostream>
#include<cmath>
#include<cstdio>
using namespace std;
long long n,e,d,T;
long double p,q;
int main(){
    freopen("decode.in","r",stdin);
    freopen("decode.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	cin>>T;
	while(T--){
		cin>>n>>e>>d;
		bool f=1;
		long long l=1,r=sqrt(n);
		while(l<r){
			p=(l+r)/2;
			q=n/p;
			int p1=(l+r)/2;
			int q1=n/p;
			if(n-p-q+2<e*d){
				l=(l+r)/2+1;
			}else if(n-p1-q1+2==e*d){
				if(p*q!=n)break;
				cout<<p1<<" "<<q1<<"\n";
				f=0;
				break;
			}else{
				r=(l+r)/2-1;
			}
		}
		if(f)cout<<"NO\n";
	}
    return 0;
}