#include<bits/stdc++.h>
using namespace std;
int k;
long long n,e,d,p,q;
int main(){
	freopen("decode.in","r",stdin);
	freopen("decode.out","w",stdout);
	
	scanf("%d",&k);
	for(int i=1;i<=k;i++){
		scanf("%lld %lld %lld",&n,&e,&d);
		long long x,y,dt,a,b,sum;
		x=n;
		y=n-e*d+2;
		dt=y*y-4*x;
		sum=sqrt(dt);
		if(dt<0||sum*sum!=dt||(y+sum)%2==1){
			cout<<"NO"<<"\n";
			continue;
		}
		if(dt==0){
			p=y/2;
			q=y/2;
			printf("%lld %lld \n",p,q);
			continue;
		}
		a=(y+sum)/2;
		b=y-a;
		p=min(a,b);
		q=max(a,b);
		printf("%lld %lld \n",p,q);
	}
	
	return 0;
}