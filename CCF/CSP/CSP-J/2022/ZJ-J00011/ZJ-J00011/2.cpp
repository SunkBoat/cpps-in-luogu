#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("decode.in","r",stdin);
	freopen("decode.out","w",stdout);
	int k;
	cin>>k;
	for(int i=1;i<=k;i++){
		long long n,d,e;
		cin>>n>>d>>e;
		unsigned long long m,h,c,p,q;
		m=n+2-e*d;
		if(m*m<4*n){
			cout<<"NO"<<endl;;
			continue;
		}
		c=sqrt(m*m-4*n);
		if(c*c!=m*m-4*n){
			cout<<"NO"<<endl;;
			continue;
		}
		p=m-c>>1;
		q=m+c>>1;
		cout<<p<<" "<<q<<endl;
	}
	return 0;
} 
