#include<bits/stdc++.h>
using namespace std;
long long t,n,x,y,k,l,r,f,m,s;
int main(){
	freopen("decode.in","r",stdin);
	freopen("decode.out","w",stdout);
	scanf("%lld",&k);
	for (int i=1;i<=k;i++){
		scanf("%lld%lld%lld",&n,&x,&y);
		t=n-x*y+2;l=1;r=t/2;f=1;
		while(l<=r){
			m=l+r>>1;s=m*(t-m);
			if(s==n){printf("%d %d\n",m,t-m);f--;break;}
			if(s<n)l=m+1;
			else r=m-1;
		}
		if(f)printf("NO\n");
	}
}
