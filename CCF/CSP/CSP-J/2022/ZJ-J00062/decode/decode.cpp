#include<bits/stdc++.h>
using namespace std;
int k,b;
long long n,e,d,m,mm;
bool f=0;
int main(){
	freopen("decode.in","r",stdin);
	freopen("decode.out","w",stdout);
	scanf("%d",&k);
	while(k!=0){
		scanf("%lld%lld%lld",&n,&e,&d);
		long long ans=e*d;
		for(int i=1;i<=n;i++){
			b=n/i*1.00;
			if(b-b/1!=0){
				f=1;
			}
			if(((i-1)*(b-1)+1) == ans){
				printf("%d %d\n",min(i,b),max(i,b));
				f=0;
				break;
			}
			f=1;
		}
		if(f==1) {
			printf("NO\n");
		}
		k--;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
