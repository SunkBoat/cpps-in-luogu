#include<iostream>
using namespace std;
long long int k,n,m,l,e,d,p,q;
int main(){
	freopen("decode.in","r",stdin);
	freopen("decode.out","w",stdout);
	scanf("%d",&k);
	for(int i=0;i<k;i++){
		scanf("%d%d%d",&n,&e,&d);
		m=e*d-2,l=n-m;
		bool flag=1;
		for(int p=1;p<l;p++){
			q=l-p;
			if(p*q==n){
				printf("%d %d\n",p,q);
				flag=0;
				break;
			}
			if(p*q>n) break;
		}
		if(flag) printf("NO\n");
	}
	return 0;
}