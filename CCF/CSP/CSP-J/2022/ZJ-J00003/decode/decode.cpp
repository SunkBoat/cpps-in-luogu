#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
void f1(){
	LL n,e,d;
	scanf("%lld %lld %lld",&n,&e,&d);
	LL m=n-e*d+2;
	for(LL p=1;p<n/p;++p){
		LL q=m-p;
		if(n==p*q){
			printf("%lld %lld\n",p,q);
			return;
		}
	}
	puts("NO");
	return;
}
int check(LL p,LL n,LL m){
	LL q=m-p;
	if(n==p*q)return -1;
	if(n>p*q)return 0;
	return 1;
}
void f2(){
	LL n,e,d;
	scanf("%lld %lld %lld",&n,&e,&d);
	LL m=n-e*d+2;
	LL l=1,r=sqrt(n);
	if(n==r*r){
		printf("%lld %lld\n",r,r);
		return;
	}
	while(l<r){
		LL ll=l,rr=r;
		LL mid=(l+r)>>1;
		int cxk=check(mid,n,m);
		if(cxk==-1){
			printf("%lld %lld\n",mid,m-mid);
			return;
		}
		else if(!cxk)l=mid+1;
		else r=mid;
		if(ll==l&&rr==r){
			puts("NO");
			return;
		}
	}
	puts("NO");
	return;
}
int main(){
	freopen("decode.in","r",stdin);
	freopen("decode.out","w",stdout);
	LL K;
	scanf("%lld",&K);
	while(K--)f2();
	return 0;
}
//n=pq,ed=(p-1)(q-1)+1=pq-p-q+2
