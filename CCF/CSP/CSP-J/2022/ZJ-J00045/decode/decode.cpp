#include<bits/stdc++.h>
using namespace std;
int k;
long long n,e,d;
int main(){
	freopen("decode.in","r",stdin);
	freopen("decode.out","w",stdout);
	cin>>k;
	while(k--){
		scanf("%lld%lld%lld",&n,&e,&d);
		long long add=n+2-e*d;
		if(add*add-4*n<0){
			cout<<"NO"<<endl;
			continue;
		}
		long long jian=sqrt(add*add-4*n);
		if(jian*jian!=add*add-4*n){
			cout<<"NO"<<endl;
			continue;
		}
		if((add+jian)%2==1||(add-jian)%2==1){
			cout<<"NO"<<endl;
			continue;
		}
		long long p=add+jian>>1,q=add-jian>>1;
		if(p>0&&q>0){
			cout<<q<<" "<<p<<endl;
			continue;
		}
		cout<<"NO"<<endl;
		continue;
	}
	return 0;
}
