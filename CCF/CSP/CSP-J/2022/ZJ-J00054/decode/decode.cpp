#include<bits/stdc++.h>
using namespace std;
int k;
long long p,q;
struct de{
	long long n,e,d;
};
de a[100005];
int main(){
    freopen("decode.in","r",stdin);
	freopen("decode.out","w",stdout);
	cin>>k;
	for(int i=0;i<k;i++){
		scanf("%lld%lld%lld",&a[i].n,&a[i].e,&a[i].d);
	}
	for(int i=0;i<k;i++){
		for(int j=1;j<=a[i].n/2+1;j++){
			if(j*j>=a[i].n){
				printf("NO\n");
				break;
			}
			if(a[i].n%j!=0){
				continue;
			}
			p=j;
			q=a[i].n/j;
			if(a[i].e*a[i].d==(p-1)*(q-1)+1){
				printf("%lld %lld\n",p,q);
				break;
			}
		}
	}
	return 0;
}
