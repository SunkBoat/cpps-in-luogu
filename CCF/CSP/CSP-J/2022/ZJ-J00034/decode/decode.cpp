#include <bits/stdc++.h>
using namespace std;
//#define int long long
#define ll long long
#define F(i,l,r) for(int i=(l);i<=(r);i++)
#define R(i,l,r) for(int i=(l);i>=(r);i--)
int main(){
	freopen("decode.in","r",stdin);
	freopen("decode.out","w",stdout);
	int k;
	ll n,d,e,m,fir,sec,p,q;/*fir=p+q sec=pq*/
	scanf("%d",&k);
	while(k--){
		scanf("%lld%lld%lld",&n,&d,&e);
		m=n-e*d+2;
		fir=m;
		sec=n;
		if(n>=(ll)(1e18)){
			if((m/2)*(m/2)==n)printf("%d %d\n",m/2,m/2);
			else printf("NO\n");
			continue;
		}
		bool write=0;
		for(p=1;p<=n/2;p++){
			if(sec%p!=0)continue;
			q=n/p;
			if(p+q==fir){
				write=1;
				printf("%d %d\n",p,q);
				break;
			}
		}
		if(!write)printf("NO\n");
	}
	return 0;
}
/*40*/