#include<bits/stdc++.h>
using namespace std;typedef long long ll;
ll T,n,p,q,anss;
ll ans(ll n,ll e){
	ll genn=(n-e)*(n-e)-4*(e-1),sqrtt,qaq,qwq;
	if(genn<0)return -1;
	sqrtt=sqrt(genn);
	if(sqrtt*sqrtt!=genn)return -1;
	if(((sqrtt+n-e)&1)==1)return -1;
	qaq=((sqrtt+n+2-e)>>1);qwq=n+2-e-qaq;
	if(qaq>qwq)swap(qaq,qwq);
	if(qaq>0&&qwq>0)printf("%lld %lld\n",qaq,qwq);
	else{
		qaq=((n+2-e-sqrtt)>>1);qwq=n+2-e-qaq;
		if(qaq>qwq)swap(qaq,qwq);
		if(qaq>0&&qwq>0)printf("%lld %lld\n",qaq,qwq);
		else return -1;
	}
	return 0;
}
int main(){
freopen("decode.in","r",stdin);freopen("decode.out","w",stdout);
	scanf("%lld",&T);
	while(T--){
		scanf("%lld%lld%lld",&n,&p,&q);
		if(ans(n,p*q)==-1)puts("NO");
	}
	return 0;
}
